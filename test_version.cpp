#define BOOST_TEST_MODULE helloworld_test_module
#include "lib.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(my_groupe_test)

BOOST_AUTO_TEST_CASE(my_first_test)
{
    BOOST_CHECK (version()>0);
}
BOOST_AUTO_TEST_SUITE_END()
