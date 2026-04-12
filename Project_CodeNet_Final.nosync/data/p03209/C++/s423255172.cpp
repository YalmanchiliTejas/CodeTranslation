#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

#define rep(i, a, b) for ( long long  i = (a); i < (b); i++ )
#define per(i, a, b) for ( long long i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

#define pr_arr(name, a, b) \
  for (int i = (a); i < (b); i++) { \
    for (int j = (a); j < (b); j++) {\
      if (j > (a)) printf(" "); \
      printf("%lld", name[i][j]); \
    }\
    printf("\n");\
  }\

#define YES puts("YES")
#define NO  puts("NO")
#define Yes puts("Yes")
#define No  puts("No")

using namespace std;

typedef long long ll;

/*
1                m    r              14
b b p p p b p b p p p b b

   b p p p b    b p p p b
   
                      b 
*/

ll X;
int N;
// brgr: レベルiのときのバーガー全体の数
//p: レベルiのパティの数
ll brgr[51], p[51];

ll dc(ll r, int level) { 
  //printf("level:%d  r:%lld\n", level, r);
  if (r<2 || r <= level+1 || level < 0) return 0;
  if (r == brgr[level] + 1LL) return p[level];
  
  ll ret = 0;
  ll m = (brgr[level]+1) / 2LL;
  
  
  if (r > m) {
     ret += 1; // 真ん中のパティ分
    ret += p[level-1];
    ret += dc(r-m, level-1);
  } else {
    ret += dc(r-1, level-1);
  }
  
  return ret;


}


int main(void) {
    scanf("%d %lld", &N, &X);
    
    brgr[0] = p[0] = 1;
    rep(i, 1, N+1) {
     brgr[i] = brgr[i-1] * 2LL + 3LL;
     p[i] = p[i-1] * 2LL +1LL;
    }
    
    ll ans = dc(X+1LL, N);
    
    printf("%lld\n", ans);

    return 0;
}
