#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60; const ll MOD = 1000000007;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//---------------------------------------------------------------------------------------------------
void _main() {
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    ll res = 0;
    if (A + B > 2 * C) {
        if ( X > Y ) {
            res = 2 * C * Y + A * (X-Y);
            chmin(res, 2 * C * X);
        }
        else {
            res = 2 * C * X + B * (Y-X);
            chmin(res, 2 * C * Y);
        }
    }else{
        res = A * X + B * Y;
    }
    cout << res << endl;
}