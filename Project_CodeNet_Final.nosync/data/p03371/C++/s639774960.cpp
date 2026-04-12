#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <cinttypes>
#include <string.h>
#include <bits/stdc++.h>

#define countof(a) (sizeof(a)/sizeof(*a))

#define vi vector<int>
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define fi first
#define se second

#define FOR(var, to)          for (register s64 var = 0; var < (s64)to; var++)
#define FROMTO(var, from, to) for (register s64 var = from; var <= (s64)to; var++)

#define INIT(var) FOR(i,countof(var)) var[i] = 0
#define INPUT(var) FOR(i,countof(var)) var[i] = ri()

#define SORT(v) qsort(v,countof(v),sizeof(*v),int_less)
#define SORTT(v) qsort(v,countof(v),sizeof(*v),int_greater)

#define MOD 1000000007
#define INF (1 << 30)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

using namespace std;

static inline int ri() {
  int a;
  scanf("%d", &a);
  return a;
}

static inline s64 rs64() {
  s64 a;
  scanf("%" SCNd64, &a);
  return a;
}

static inline void wi(int a) {
  printf("%d", a);
}

static inline void wu64(u64 a) {
  printf("%" PRIu64, a);
}

static inline void ws64(s64 a) {
  printf("%" PRId64, a);
}

int int_less(const void *a, const void *b) {
  return (*((const int*)a) - *((const int*)b));
}
int int_greater(const void *a, const void *b) {
  return (*((const int*)b) - *((const int*)a));
}

int main() {
    int a = ri();
    int b = ri();
    int c = ri();
    int x = ri();
    int y = ri();
    int res = min(min(x*a+y*b, c*2*max(x,y)), c*2*min(x,y)+((x>y)?a:b)*(max(x,y)-min(x,y)));
    cout << res << endl;
 return 0;
}
