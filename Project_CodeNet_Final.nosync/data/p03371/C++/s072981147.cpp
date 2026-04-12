#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if(a + b < 2 * c) {
        if(x > y) {
            ans = (a + b) * y + min(2 * c * (x - y), a * (x - y));
        }
        else {
            ans = (a + b) * x + min(2 * c * (y - x), b * (y - x));
        }
    }
    else {
        if(x > y) {
            ans = y * 2 * c + min(a, 2 * c) * (x - y);
        }
        else {
            ans = x * 2 * c + min(b, 2 * c) * (y - x);
        }
    }
    cout << ans << endl;
}
