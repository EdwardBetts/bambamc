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
#if ! defined(BAMBAM_SAMBAMFILEDECODER_H)
#define BAMBAM_SAMBAMFILEDECODER_H

#include <bambamc/BamBam_BamFileDecoder.h>
#include <bambamc/BamBam_SamFileDecoder.h>

typedef struct _BamBam_SamBamFileDecoder
{
	BamBam_BamFileDecoder * bamdecoder;
	BamBam_SamFileDecoder * samdecoder;
	BamBam_BamFileHeader * header;	
} BamBam_SamBamFileDecoder;

extern BamBam_BamSingleAlignment * BamBam_SamBamFileDecoder_DecodeAlignment(BamBam_SamBamFileDecoder * object);
extern BamBam_SamBamFileDecoder * BamBam_SamBamFileDecoder_Delete(BamBam_SamBamFileDecoder * object);
extern BamBam_SamBamFileDecoder * BamBam_SamBamFileDecoder_New(char const * filename, char const * mode);
#endif
