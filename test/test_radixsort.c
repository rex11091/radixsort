#include "unity.h"
#include "radixsort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_radixsort_print_function(void)
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr,n);
}

void test_radixsort_getHighest(void)
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m;

    m = getHighest(arr,n);
    printf("%d\n",m );
    TEST_ASSERT_EQUAL(802,m);
}

void test_radixsort_from_unsort_to_sort_test1(void)
{
  int arr[] = { 170, 2, 75, 90, 802};
  int arr1[] ={2,75,90,170,802};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixsort(arr, n);
  print(arr1, n);

  TEST_ASSERT_EQUAL_INT_ARRAY(arr1,arr,n);
}

void test_radixsort_from_unsort_to_sort_test2_with_duplicate_number(void)
{
  int arr[] = { 9, 0, 9, 702};
  int ans[] = {0,9,9,702};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixsort(arr, n);
  print(arr, n);

  TEST_ASSERT_EQUAL_INT_ARRAY(ans,arr,n);
}

void test_radixsort_from_unsort_to_sort_test3_with_zero_element(void)
{
  int arr[] = { 9, 0, 10, 702};
  int ans[] = {0,9,10,702};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixsort(arr, n);
  print(arr, n);

  TEST_ASSERT_EQUAL_INT_ARRAY(ans,arr,n);
}
