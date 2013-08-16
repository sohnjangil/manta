// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Manta
// Copyright (c) 2013 Illumina, Inc.
//
// This software is provided under the terms and conditions of the
// Illumina Open Source Software License 1.
//
// You should have received a copy of the Illumina Open Source
// Software License 1 along with this program. If not, see
// <https://github.com/downloads/sequencing/licenses/>.
//

#include "boost/test/unit_test.hpp"

#include "blt_util/align_path.hh"


BOOST_AUTO_TEST_SUITE( test_align_path )


BOOST_AUTO_TEST_CASE( test_apath_clean_seqinfo )
{
    const std::string testCigar("10M1D10=2X10=1D1M1=1=1X1=1X");
    ALIGNPATH::path_t testPath;
    cigar_to_apath(testCigar.c_str(), testPath);

    apath_clean_seqinfo(testPath);

    BOOST_REQUIRE_EQUAL(apath_to_cigar(testPath), "10M1D22M1D6M");
}


BOOST_AUTO_TEST_SUITE_END()

