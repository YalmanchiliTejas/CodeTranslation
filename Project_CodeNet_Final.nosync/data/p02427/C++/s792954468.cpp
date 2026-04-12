#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define long long long
#define LF '\n'
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;


signed main()
{
  int N;
  scanf("%d", &N);
  for (int i = 0; i < (1 << N); ++i) {
    printf("%d:", i);

    for (int j = 0; j < N; ++j) {
      if((i>>j) & 1) printf(" %d", j);
    }
    puts("");
  }

  return 0;
}


