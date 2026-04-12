#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
#define INF 1100000000

int A, B, C, X, Y;

int solve(){
    int ans = 0;
    int min_v = min(X,Y);
    ans += (C * min_v * 2 <= (A + B) * min_v ? C * min_v * 2 : (A + B) * min_v);
    if ((X - min_v) > 0)
        ans += (A * (X - min_v) <= C * 2 * (X - min_v) ? A * (X - min_v) : C * 2 * (X - min_v));
    else if ((Y - min_v) > 0)
        ans += (B * (Y - min_v) <= C * 2 * (Y - min_v) ? B * (Y - min_v) : C * 2 * (Y - min_v));
    
    return ans;
}

int main(){
  cin >> A >> B >> C >> X >> Y;
  cout << solve() << endl;
  return 0;
}
