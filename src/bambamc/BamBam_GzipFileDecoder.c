/**
    bambamc
    Copyright (C) 2009-2013 German Tischler
    Copyright (C) 2011-2013 Genome Research Limited

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#include <bambamc/BamBam_GzipFileDecoder.h>

BamBam_BamSingleAlignment * BamBam_GzipFileDecoder_DecodeAlignment(BamBam_GzipFileDecoder * object)
{
	int const r = BamBam_BamSingleAlignment_LoadAlignment(object->alignment,object->reader);
	
	if ( r > 0 )
		return object->alignment;
	else
		return 0;
}

BamBam_GzipFileDecoder * BamBam_GzipFileDecoder_Delete(BamBam_GzipFileDecoder * object)
{
	if ( object )
	{
		if ( object->alignment )
		{
			BamBam_BamSingleAlignment_Delete(object->alignment);
			object->alignment = 0;
		}
		if ( object->reader )
		{
			BamBam_GzipReader_Delete(object->reader);
			object->reader = 0;
		}
		free(object);
	}
	return 0;
}

BamBam_GzipFileDecoder * BamBam_GzipFileDecoder_New(char const * filename)
{
	BamBam_GzipFileDecoder * object = 0;
	
	object = (BamBam_GzipFileDecoder *)malloc(sizeof(BamBam_GzipFileDecoder));
	
	if ( ! object )
		return BamBam_GzipFileDecoder_Delete(object);
		
	object->reader = BamBam_GzipReader_New(filename);
	
	if ( ! object->reader )
		return BamBam_GzipFileDecoder_Delete(object);
		
	object->alignment = BamBam_BamSingleAlignment_New();

	if ( ! object->alignment )
		return BamBam_GzipFileDecoder_Delete(object);
	
	return object;
}
