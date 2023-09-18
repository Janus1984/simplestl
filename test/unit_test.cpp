#include <gtest/gtest.h>
#include "simplestl.h"

namespace ncnn {

// max function positive test case
TEST(MaxFunctionTest, PositiveCase)
{
    int a = 5;
    int b = 10;
    EXPECT_EQ(max(a, b), b);
}

// max function negative test case
TEST(MaxFunctionTest, NegativeCase)
{
    int a = 10;
    int b = 5;
    EXPECT_EQ(max(a, b), a);
}

// min function positive test case
TEST(MinFunctionTest, PositiveCase)
{
    int a = 5;
    int b = 10;
    EXPECT_EQ(min(a, b), a);
}

// min function negative test case
TEST(MinFunctionTest, NegativeCase)
{
    int a = 10;
    int b = 5;
    EXPECT_EQ(min(a, b), b);
}

// swap function positive test case
TEST(SwapFunctionTest, PositiveCase)
{
    int a = 5;
    int b = 10;
    swap(a, b);
    EXPECT_EQ(a, 10);
    EXPECT_EQ(b, 5);
}

// pair comparison operators positive test case
TEST(PairComparisonTest, PositiveCase)
{
    pair<int, int> p1(5, 10);
    pair<int, int> p2(5, 10);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 < p2);
    EXPECT_FALSE(p1 > p2);
    EXPECT_TRUE(p1 <= p2);
    EXPECT_TRUE(p1 >= p2);
}

// pair comparison operators negative test case
TEST(PairComparisonTest, NegativeCase)
{
    pair<int, int> p1(5, 10);
    pair<int, int> p2(10, 5);
    EXPECT_FALSE(p1 == p2);
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p1 > p2);
    EXPECT_TRUE(p1 <= p2);
    EXPECT_FALSE(p1 >= p2);
}

// make_pair function positive test case
TEST(MakePairFunctionTest, PositiveCase)
{
    pair<int, int> p = make_pair(5, 10);
    EXPECT_EQ(p.first, 5);
    EXPECT_EQ(p.second, 10);
}

}  // namespace ncnn

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
