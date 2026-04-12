#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if(A+B <= 2*C){
        cout << A*X + B*Y;
    }else{
      ll ans = 0;
      ans = min(X,Y) * 2 * C;
      ll tmp = min(X,Y);
      X = X - tmp;
      Y = Y - tmp;
      ans += X * min(A,2 * C) + Y * min(B,2 * C);
      cout << ans;

    }
}
