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

    int first = min(a+b, 2*c);
    int ans = min(x,y) * first;

    if(x == y) {
        // do nothing
    } else if(x > y) {
        ans += (x-y) * min(a, 2*c);
    } else {
        ans += (y-x) * min(b, 2*c);
    }

    cout << ans << endl;

    return 0;
}

