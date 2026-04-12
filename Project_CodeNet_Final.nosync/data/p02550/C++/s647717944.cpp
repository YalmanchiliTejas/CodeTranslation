#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL;
#define all(a) begin(a),end(a)
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

lli MOD = 998244353;

int main()
{   _
    lli n, x, m; cin >> n >> x >> m;
    x %= m;
    vector<lli> occ(m + 10, -1);
    occ[x] = 0;
    vector<lli> acum(m + 10, 0);
    acum[0] = x;
    lli last = x;
    lli l, r;
    fore(i, 1, m + 10) {
        lli nxt = (last * last) % m;
        if(occ[nxt] != -1) {
            l = occ[nxt];
            r = i;
            break;
        }
        occ[nxt] = i;
        acum[i] += acum[i - 1] + nxt;
        last = nxt;
    }
    if(n <= r) {
        cout << acum[n - 1] << ENDL;
        return 0;
    }
    ///deb(l);
    ///deb(r);
    lli rest = n - l;
    ///deb(rest);
    lli length = r - l;
    ///deb(length);
    lli rep = (rest - rest % length) / length;
    ///deb(rep);
    lli left = rest % length;
    ///deb(left);
    lli cycleVal = acum[r - 1];
    if(l > 0) cycleVal -= acum[l - 1];
    ///deb(cycleVal);
    lli ans = cycleVal * rep;
    if(left + l > 0) ans += acum[left + l - 1];
    cout << ans << ENDL;
    return 0;
}
