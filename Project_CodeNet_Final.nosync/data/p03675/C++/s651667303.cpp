#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

//--------------------------------------------
const double EPS = 1e-14;
const double PI  = acos(-1.0);

//--------------------------------------------

int main(){
  int n;
  int a;

  scanf("%d",&n);

  int b[n];
  REP (i, n) {
    scanf("%d",&a);
    if (i % 2 == 0) b[(n + i) / 2] = a;
    else b[(n - i - 1) / 2] = a;
  }

  if (n % 2 == 0) {
    REP(i, n) {
      printf("%d",b[i]);
      i < (n - 1) ? printf(" ") : printf("\n");
    }
  } else {
    RREP(i, n) {
      printf("%d",b[i]);
      i > 0 ? printf(" ") : printf("\n");
    }
  }

}
