#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int nxt[100010];

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    ll a = x;
    rep(i, 100010) nxt[i] = -1;
    ll s, g;

    while(1){
        ll b = a * a % m;
        nxt[a] = b;
        if (nxt[b] != -1) {
            s = b;
            g = a;
            break;
        }
        a = b;
    }
    ll v = x;
    ll cnt_pre = 0;
    ll sum_pre = v;

    while(1){
        cnt_pre++;
        ll nv = nxt[v];
        if (nv == s) break;
        sum_pre += nv;
        v = nv;
    }

    ll cnt_loop = 1;
    v = s;
    ll sum_loop = v;
    while(1){
        cnt_loop++;
        ll nv = nxt[v];
        sum_loop += nv;
        if (nv == g) break;
        v = nv;
    }

    // cout << "s:" << s << " g:" << g << endl;
    // cout << "cnt_loop:" << cnt_loop << " cnt_pre:" << cnt_pre << endl;
    // cout << "sum_loop:" << sum_loop << " sum_pre:" << sum_pre << endl;

    ll ans = 0;
    v = x;
    if (n <= cnt_pre){
        while(n--){
            ans += v;
            v = nxt[v];
        }
        cout << ans << endl;
        return 0;
    }

    ll show = (n - cnt_pre) / cnt_loop;
    ll res = (n - cnt_pre) % cnt_loop;

    ans += sum_pre;
    ans += show * sum_loop;
    
    v = s;
    rep(i, res){
        ans += v;
        v = nxt[v];
    }

    cout << ans << endl;

    return 0;
}
