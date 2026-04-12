#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (2 * c < a + b) {
        ans = min(x, y) * 2 * c;
        if (x > y) {
            if ((x - y) * a > 2 * (x - y) * c) ans += 2 * (x - y) * c;
            else ans += (x - y) * a;
        } else {
            if ((y - x) * b > 2 * (y - x) * c) ans += 2 * (y - x) * c;
            else ans += (y - x) * b;
        }
    } else {
        ans = x * a + y * b;
    } 
    cout << ans << "\n";
}