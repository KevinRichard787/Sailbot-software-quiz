#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);
}

void test_bound_basic2(CuTest *tc) {
    CuAssertDblEquals(tc, 140, bound_to_180(140), 0.0001);
}

void test_bound_basic3(CuTest *tc) {
    CuAssertDblEquals(tc, -120.5, bound_to_180(-120.5), 0.0001);
}

void test_bound_basic4(CuTest *tc) {
    CuAssertDblEquals(tc, -160, bound_to_180(200), 0.0001);
}

void test_bound_basic5(CuTest *tc) {
    CuAssertDblEquals(tc, 159.1, bound_to_180(-200.9), 0.0001);
}

void test_bound_basic6(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(1080), 0.0001);
}
void test_bound_basic7(CuTest *tc) {
    CuAssertDblEquals(tc, 160, bound_to_180(160), 0.0001);
}
void test_bound_basic8(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(-720), 0.0001);
}
void test_bound_basic9(CuTest *tc) {
    CuAssertDblEquals(tc, -80, bound_to_180(-800), 0.0001);
}
/**************** Tests for is_angle_between() *******************/

///first smaller, middle in between, true, 
void test_between_basic1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0, 1, 2));
}

void test_between1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(360, 361, 362));
}

void test_between2(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(-365, -363 , -361));
}
void test_between3(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(-2, -1 , 0));
}

//first smaller, middle in between, false
void test_between4(CuTest *tc) {
    CuAssertTrue(tc, !is_angle_between(40.5, 60, 270));
}

void test_between5(CuTest *tc) {
    CuAssertTrue(tc, !is_angle_between(440, 460, 670));
}

void test_between6(CuTest *tc) {
    CuAssertTrue(tc, !is_angle_between(-550, 180 , 358));
}

///others
void test_between7(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(10, 355 , 350));
}

void test_between8(CuTest *tc) {
    CuAssertTrue(tc, !is_angle_between(10, 120 , 350));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_bound_basic2);
    SUITE_ADD_TEST(suite, test_bound_basic3);
    SUITE_ADD_TEST(suite, test_bound_basic4);
    SUITE_ADD_TEST(suite, test_bound_basic5);
    SUITE_ADD_TEST(suite, test_bound_basic6);
    SUITE_ADD_TEST(suite, test_bound_basic7);
    SUITE_ADD_TEST(suite, test_bound_basic8);
    SUITE_ADD_TEST(suite, test_bound_basic9);

    SUITE_ADD_TEST(suite, test_between_basic1);
    SUITE_ADD_TEST(suite, test_between1);
    SUITE_ADD_TEST(suite, test_between2);
    SUITE_ADD_TEST(suite, test_between3);
    SUITE_ADD_TEST(suite, test_between4);
    SUITE_ADD_TEST(suite, test_between5);
    SUITE_ADD_TEST(suite, test_between6);
    SUITE_ADD_TEST(suite, test_between7);
    SUITE_ADD_TEST(suite, test_between8);
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}