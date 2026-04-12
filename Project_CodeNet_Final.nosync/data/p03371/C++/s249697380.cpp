#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, a, b) for(int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
const int INF = 1e9;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if(2*c > a + b) {
        ans = a*x + b*y;
    } else {
        ans = 2*c*min(x, y);
        if(x > y) {
            ans += (x-y)*a;
        }else{
            ans += (y-x)*b;
        }
        ans = min(ans, (ll)2*c*max(x, y));
    }
    cout << ans << endl;
}