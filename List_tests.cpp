// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_empty) {
  List<int> list;

  ASSERT_TRUE(list.empty());

  list.push_front(1);

  ASSERT_FALSE(list.empty());

  list.pop_front();

  ASSERT_TRUE(list.empty());
}

TEST(test_size) {
  List<int> list;

  ASSERT_EQUAL(list.size(), 0);

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);

  ASSERT_EQUAL(list.size(), 3);

  list.clear();

  ASSERT_EQUAL(list.size(), 0);
}

TEST(test_front_back) {
  List<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.back(), 3);

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);

  ASSERT_EQUAL(list.front(), 3);
  ASSERT_EQUAL(list.back(), 3);
}

TEST(test_push_front) {
  List<int> list;

  list.push_front(1);

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.back(), 1);
  ASSERT_EQUAL(list.size(), 1);

  list.push_front(2);

  ASSERT_EQUAL(list.front(), 2);
  ASSERT_EQUAL(list.back(), 1);
  ASSERT_EQUAL(list.size(), 2);
}

TEST(test_push_back) {
  List<int> list;

  list.push_back(1);

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.back(), 1);
  ASSERT_EQUAL(list.size(), 1);

  list.push_back(2);

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.back(), 2);
  ASSERT_EQUAL(list.size(), 2);
}

TEST(test_pop_front) {
  List<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);

  list.pop_front();

  ASSERT_EQUAL(list.front(), 2);
  ASSERT_EQUAL(list.size(), 2);

  list.pop_front();

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.size(), 1);
}

TEST(test_pop_back) {
  List<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);

  list.pop_back();

  ASSERT_EQUAL(list.back(), 2);
  ASSERT_EQUAL(list.size(), 2);

  list.pop_back();

  ASSERT_EQUAL(list.back(), 3);
  ASSERT_EQUAL(list.size(), 1);
}

TEST(test_clear) {
  List<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);

  ASSERT_FALSE(list.empty());

  list.clear();

  ASSERT_TRUE(list.empty());
}

TEST(test_default_ctor) {
  List<int> list;

  ASSERT_EQUAL(list.size(), 0);
}

TEST(test_copy_ctor) {
  List<int> list1;

  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);

  List<int> list2(list1);

  ASSERT_EQUAL(list2.front(), 1);

  list2.pop_front();

  ASSERT_EQUAL(list2.front(), 2);

  list2.pop_front();

  ASSERT_EQUAL(list2.front(), 3);

  list2.pop_front();

  ASSERT_TRUE(list2.empty());
}

TEST(test_assign_op) {
  List<int> list1;

  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);

  List<int> list2 = list1;

  ASSERT_EQUAL(list2.front(), 1);

  list2.pop_front();

  ASSERT_EQUAL(list2.front(), 2);

  list2.pop_front();

  ASSERT_EQUAL(list2.front(), 3);

  list2.pop_front();

  ASSERT_TRUE(list2.empty());
}

TEST(test_iter_plus_and_minus_ops) {
  List<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  List<int>::Iterator iter = list.begin();

  ASSERT_EQUAL(*iter, 1);

  ASSERT_EQUAL(*(++iter), 2);
  ASSERT_EQUAL(*(++iter), 3);

  ASSERT_EQUAL(*(--iter), 2);
  ASSERT_EQUAL(*(--iter), 1);
}

TEST(test_iter_equality_ops) {
  List<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  List<int>::Iterator iter1 = list.begin();
  List<int>::Iterator iter2 = list.begin();

  ASSERT_TRUE(iter1 == iter2);
  ASSERT_TRUE(++iter1 != iter2);
  ASSERT_TRUE(iter1 == ++iter2);
  ASSERT_TRUE(++iter1 == ++iter2);
  ASSERT_TRUE(++iter1 != iter2);
  ASSERT_TRUE(iter1 == list.end());
  ASSERT_TRUE(++iter2 == list.end());
}

TEST(test_iter_begin_and_end) {
  List<int> list;

  ASSERT_EQUAL(list.begin(), list.end());

  list.push_back(1);

  ASSERT_NOT_EQUAL(list.begin(), list.end());

  list.push_back(2);
  list.push_back(3);

  List<int>::Iterator iter = list.begin();

  ASSERT_EQUAL(*iter, 1);
  ASSERT_EQUAL(++(++(++iter)), list.end());
}

TEST(test_iter_erase) {
  List<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.erase(list.begin());

  ASSERT_EQUAL(list.front(), 2);
  ASSERT_EQUAL(list.size(), 2);

  list.erase(list.begin());

  ASSERT_EQUAL(list.front(), 3);
  ASSERT_EQUAL(list.size(), 1);

  list.erase(list.begin());

  ASSERT_TRUE(list.empty());

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.erase(++(++list.begin()));

  ASSERT_EQUAL(list.back(), 2);
  ASSERT_EQUAL(list.size(), 2);

  list.erase(++list.begin());

  ASSERT_EQUAL(list.back(), 1);
  ASSERT_EQUAL(list.size(), 1);

  list.erase(list.begin());

  ASSERT_TRUE(list.empty());

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.erase(++list.begin());

  ASSERT_EQUAL(*(++list.begin()), 3);
}

TEST(test_iter_insert) {
  List<int> list;

  list.push_front(3);

  list.insert(list.begin(), 2);

  ASSERT_EQUAL(list.front(), 2);
  ASSERT_EQUAL(list.size(), 2);

  list.insert(list.begin(), 1);

  ASSERT_EQUAL(list.front(), 1);
  ASSERT_EQUAL(list.size(), 3);

  list.clear();
  list.push_back(1);
  list.push_back(3);

  list.insert(++list.begin(), 2);

  ASSERT_EQUAL(*(++list.begin()), 2);
}

TEST_MAIN()
