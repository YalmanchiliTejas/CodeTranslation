#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;

int main() {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long ans = 0;
  
  if (A + B <= C + C){
    if (A > C+C) {
      ans += (C+C)*X;
    } else{
      ans += A*X;
    }

    if (B > C+C) {
      ans += (C+C)*Y;
    } else{
      ans += B*Y;
    }

  } else {
    if(X > Y){
      ans = Y*(C+C);
      if(A > C+C){
        ans += (X-Y)*(C+C);
      } else{
        ans += (X-Y)*A;
      }
    } else{
      ans = X*(C+C);
      if(B > C+C){
        ans += (Y-X)*(C+C);
      } else{
        ans += (Y-X)*B;
      }
    }

  }

  cout << ans << endl;
}
