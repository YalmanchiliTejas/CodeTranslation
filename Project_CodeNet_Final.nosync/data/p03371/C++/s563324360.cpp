#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    ll ans = 0;
    
    if ( A + B <= 2 * C ){
        ans = A * X + B * Y;
    } else {
        ans = ans + 2 * C * min(X,Y);
        //cout << ans << endl;
        if ( X > Y ){
            if ( A < 2 * C ) ans = ans + A * llabs(X-Y);
            else ans = ans + 2 * C * llabs(X-Y);
        } else {
            if ( B < 2 * C ) ans = ans + B * llabs(X-Y);
            else ans = ans + 2 * C * llabs(X-Y);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
