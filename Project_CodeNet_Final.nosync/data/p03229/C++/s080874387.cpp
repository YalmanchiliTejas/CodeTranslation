#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>

using namespace std;

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX_N (100000)

int main(int argc, char *argv[]) {
  long N, A[MAX_N];
  deque<long> B;

  // read inputs
  scanf("%ld", &N);
  for (long i = 0; i < N; i++)
    scanf("%ld", &A[i]);
  sort(A, A + N);
  // for (long i = 0; i < N; i++)
  //   printf("%ld ", A[i]);
  // printf("\n");

  // create B
  long l = 1, r = N - 1;
  B.push_back(A[0]);
  for (long k = 1; k < N; k++) {
    long left_elem = B.front(), right_elem = B.back();
    long diff1 = ABS(A[l] - left_elem);
    long diff2 = ABS(A[r] - left_elem);
    long diff3 = ABS(A[l] - right_elem);
    long diff4 = ABS(A[r] - right_elem);
    if (diff1 >= diff2 && diff1 >= diff3 && diff1 >= diff4) {
      B.push_front(A[l++]);
    } else if (diff2 >= diff1 && diff2 >= diff3 && diff2 >= diff4) {
      B.push_front(A[r--]);
    } else if (diff3 >= diff1 && diff3 >= diff2 && diff3 >= diff4) {
      B.push_back(A[l++]);
    } else {
      B.push_back(A[r--]);      
    }
  }
  long ans_B = 0;
  long prev = B.front();
  B.pop_front();
  while (!B.empty()) {
    // printf("%ld ", prev);
    long cur = B.front();
    B.pop_front();
    ans_B += ABS(cur - prev);
    prev = cur;
  }
  // printf("%ld\n", prev);
  printf("%ld\n", ans_B);
  
  return 0;
}
