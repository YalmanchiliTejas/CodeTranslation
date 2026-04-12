#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }



int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    if(a+b < c*2) {
        // 全て個別に買った方がとく
        cout << a*x + b*y << endl;
        return 0;
    } else {
        // とりあえずa,bどちらかの必要文揃うまでは、c２枚がとく
        ll ans = min(x,y) * (2*c);
        if(x==y) {
            cout << ans << endl;
            return 0;
        }
        if(x > y) {
            if(a < 2*c) {
                ans += (x-y) * a;
                cout << ans << endl;
                return 0;
            } else {
                ans += (x-y) * (2*c);
                cout << ans << endl;
                return 0;
            }
        } else {
            if(b < 2*c) {
                ans += (y-x) * b;
                cout << ans << endl;
                return 0;
            } else {
                ans += (y-x) * (2*c);
                cout << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}

