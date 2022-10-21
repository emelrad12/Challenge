#include "gtest/gtest.h"
#include "../DefaultList.h"

#define specialTests false
TEST(Append_Test, Empty_List) {
    auto list1 = DefaultList<int>();
    auto list2 = DefaultList<int>();
    list1.Append(list2);
    auto newList = DefaultList<int>();
    ASSERT_TRUE(list1.Equals(newList));
}

TEST(Append_Test, Empty_list_to_list) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    auto list2 = DefaultList<int>();
    list1.Append(list2);
    ASSERT_TRUE(list1.Equals(list1));
}

TEST(Append_Test, List_to_list) {
    auto list1 = DefaultList<int>({1, 2});
    auto list2 = DefaultList<int>({2, 3, 4, 5});
    list1.Append(list2);
    auto newList = DefaultList<int>({1, 2, 2, 3, 4, 5});
    ASSERT_TRUE(list1.Equals(newList));
}

TEST(Concat, One) {
    auto list1 = DefaultList<int>();
    auto list2 = DefaultList<int>();
    ASSERT_TRUE(list1.Concatenate(list2).Equals({}));
}

#if specialTests
TEST(Concat, Two) {
    auto list1 = DefaultList<int>({1, 2});
    auto list2 = DefaultList<int>({3});
    auto list3 = DefaultList<int>({});
    auto list4 = DefaultList<int>({4, 5, 6});
    auto listOfLists = DefaultList<DefaultList<int>>({list2, list3, list4});
    ASSERT_TRUE(list1.Concatenate(listOfLists)).Equals({1, 2, 3, 4, 5, 6})
}
#endif

TEST(Filter, Empty_List) {
    auto list1 = DefaultList<int>();
    auto filteredList = list1.Filter([](int el) -> bool { return el % 2 == 1; });
    ASSERT_TRUE(filteredList.Equals({}));
}

TEST(Filter, Non_empty_List) {
    auto list1 = DefaultList<int>({1, 2, 3, 5});
    auto filteredList = list1.Filter([](int el) -> bool { return el % 2 == 1; });
    ASSERT_TRUE(filteredList.Equals({}));
}

//This test passes anyways lol
TEST(Length, Empty_list) {
    auto list1 = DefaultList<int>();
    EXPECT_EQ(list1.Length(), 0);
}

TEST(Length, Non_empty_list) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    EXPECT_EQ(list1.Length(), 4);
}

TEST(Map, Empty_list) {
    auto list1 = DefaultList<int>();
    auto mappedList = list1.Map([](int el) -> int { return ++el; });
    ASSERT_TRUE(mappedList.Equals({}));
}

TEST(Map, Non_empty_list) {
    auto list1 = DefaultList<int>({1, 3, 5, 7});
    auto mappedList = list1.Map([](int el) -> int { return ++el; });
    ASSERT_TRUE(mappedList.Equals({2, 4, 6, 8}));
}

TEST(FoldL, Empty_list) {
    auto list1 = DefaultList<int>();
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return el * acc; }, 2);
    EXPECT_EQ(result, 2);
}

TEST(FoldL, Direction_independent) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return el * acc; }, 5);
    EXPECT_EQ(result, 15);
}

TEST(FoldL, Direction_dependent) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return el / acc; }, 24);
    EXPECT_EQ(result, 64);
}

TEST(FoldR, Reduce_from_right) {
    auto list1 = DefaultList<int>();
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return el * acc; }, 2);
    EXPECT_EQ(result, 2);
}

TEST(FoldR, Direction_independent_non_empty) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return acc + el; }, 5);
    EXPECT_EQ(result, 15);
}

TEST(FoldR, Direction_dependent_non_empty) {
    auto list1 = DefaultList<int>({1, 2, 3, 4});
    auto result = list1.FoldL<int>([](int el, int acc) -> int { return el / acc; }, 24);
    EXPECT_EQ(result, 9);
}

TEST(Reverse, Empty_list) {
    auto list1 = DefaultList<int>();
    auto result = list1.Reverse();
    ASSERT_TRUE(result.Equals({}));
}

TEST(Reverse, Non_empty_list) {
    auto list1 = DefaultList<int>({1, 3, 5, 7});
    auto result = list1.Reverse();
    ASSERT_TRUE(result.Equals({7, 5, 3, 1}));
}

//This test is not really doable as it relies on typescript magic
//Here is the original code. Attempt at your won risk
//xit('list of lists is not flattened', () => {
//  const list1 = List.create([1, 2], [3], [], [4, 5, 6])
//  expect(list1.reverse()).toHaveValues([4, 5, 6], [], [3], [1, 2])
//})

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}