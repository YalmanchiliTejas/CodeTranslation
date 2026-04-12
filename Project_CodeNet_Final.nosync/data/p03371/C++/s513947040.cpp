#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    ll a,b,c,x,y,m,ans;
    cin >> a >> b >> c >> x >> y;
    m = min(x, y);
    ans = m * min(2 * c, a + b) + (x - m) * min(2 * c, a) + (y - m) * min(2 * c, b);

    cout << ans << endl;

}