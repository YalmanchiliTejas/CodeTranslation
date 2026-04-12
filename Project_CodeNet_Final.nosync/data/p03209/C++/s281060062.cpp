#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX

const double EPS = 1e-14;
const double PI  = acos(-1.0);


LL num[51];
LL ps[51];

LL solve(LL n, LL x) {
  if (n == 0 && x <= 0) return 0;
  else if (x == num[n]) return ps[n];
  else if (x < num[n] / 2 + 1) return solve(n - 1, x - 1);
  else if (x == num[n] / 2 + 1) return solve(n - 1, num[n] / 2 - 1) + 1;
  else return solve(n - 1, num[n] / 2 - 1) + 1 + solve(n - 1, x - (num[n] / 2 + 1));
}

int main(){
  LL n, x;
  cin >> n >> x;

  num[0] = 1;
  FOR (i, 1, n + 1) {
    num[i] = num[i - 1] * 2 + 3;
  }

  ps[0] = 1;
  FOR (i, 1, n + 1) {
    ps[i] = ps[i - 1] * 2 + 1;
  }

  cout << solve(n, x) << endl;
}
