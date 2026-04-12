#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>

#define MAX_N (200000L)
#define MAX_M (200000L)
#define NUM_ELEM (1L << 18)
// #define NUM_ELEM (1L << 4)
#define SIZE_BUF (2 * NUM_ELEM - 1)
#define INF (1000000000000000000L)

using namespace std;

long buf[SIZE_BUF], add[SIZE_BUF];

void st_init() {
  for (int i = 0; i < SIZE_BUF; i++) {
    buf[i] = -INF;
    add[i] = 0;
  }
}

void st_update(long k, long v) {
  long cur = NUM_ELEM - 1 + k;
  buf[cur] = v;
  while (cur > 0) {
    const long par = (cur - 1) / 2;
    const long chl = 2 * par + 1, chr = 2 * par + 2;
    buf[par] = max(buf[chl] + add[chl], buf[chr] + add[chr]);
    cur = par;
  }
}

void st_add_r(long queryb, long querye, long cur, long curb, long cure,
              long x) {
  if (queryb >= cure || querye <= curb) {  // no intersection
    return;
  } else if (queryb <= curb && cure <= querye) {  // current section included
    add[cur] += x;
  } else {  // current section includes query
    const long chl = 2 * cur + 1, chr = 2 * cur + 2;
    const long m = (curb + cure) / 2;
    st_add_r(queryb, querye, chl, curb, m, x);
    st_add_r(queryb, querye, chr, m, cure, x);
    buf[cur] = max(buf[chl] + add[chl], buf[chr] + add[chr]);
  }
}

void st_add(long queryb, long querye, long x) {
  st_add_r(queryb, querye, 0, 0, NUM_ELEM, x);
}

void st_print() {
  printf("buf:\n");
  for (int k = 1; k <= NUM_ELEM; k *= 2) {
    for (int i = 0; i < k; i++) {
      printf("%ld ", buf[k - 1 + i]);
    }
    printf("\n");
  }
  printf("add:\n");
  for (int k = 1; k <= NUM_ELEM; k *= 2) {
    for (int i = 0; i < k; i++) {
      printf("%ld ", add[k - 1 + i]);
    }
    printf("\n");
  }
}

long st_query_r(long queryb, long querye, long cur, long curb, long cure) {
  if (queryb >= cure || querye <= curb) {  // no intersection
    return -INF;
  } else if (queryb <= curb && querye >= cure) {  // current section included
    return buf[cur] + add[cur];
  } else {  // currect section includes query
    const long chl = 2 * cur + 1, chr = 2 * cur + 2;
    const long m = (curb + cure) / 2;
    return max(st_query_r(queryb, querye, chl, curb, m),
               st_query_r(queryb, querye, chr, m, cure)) +
           add[cur];
  }
}

long st_query(long queryb, long querye) {
  return st_query_r(queryb, querye, 0, 0, NUM_ELEM);
}

pair<pair<long, long>, long> ranges[MAX_M];

int main() {
  // read inputs
  long N, M, ls[MAX_M], rs[MAX_M], as[MAX_M];
  scanf("%ld %ld", &N, &M);
  for (long k = 0; k < M; k++) {
    scanf("%ld %ld %ld", &ls[k], &rs[k], &as[k]);
    ls[k]--;  // NOTE : modified input
    rs[k]--;  // NOTE : modified input
  }

  // sort the ranges
  for (long k = 0; k < M; k++) {
    ranges[k] = make_pair(make_pair(ls[k], rs[k]), as[k]);
  }
  sort(ranges, ranges + M);
  // for (long k = 0; k < M; k++) {
  //   const long l = ranges[k].first.first, r = ranges[k].first.second,
  //              a = ranges[k].second;
  //   printf("k = %ld, l = %ld, r = %ld, a = %ld\n", k, l, r, a);
  // }

  // solve dp
  // initialize
  st_init();
  st_update(N, 0);
  // update
  long k = M - 1;
  for (long i = N - 1; i >= 0; i--) {
    // include ranges k with ls[k] >= i
    while (k >= 0 && ranges[k].first.first >= i) {
      const long l = ranges[k].first.first, r = ranges[k].first.second,
                 a = ranges[k].second;
      st_add(l + 1, (r + 1) + 1, a);
      // printf("add range: b = %ld, e = %ld, v = %ld\n", l + 1, r + 1 + 1, a);
      k--;
    }
    st_update(i, max(st_query(i + 1, N + 1), 0L));
    // printf("i = %ld\n", i);
    // st_print();
  }
  printf("%ld\n", st_query(0, 1));
}
