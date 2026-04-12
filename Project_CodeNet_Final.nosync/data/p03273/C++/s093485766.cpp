#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(V) rep(i, V.size()) cout << V[i] << " ";
const ll INF = 1LL << 61;
const ll MOD = 1000000007 /*988244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, h, x, y, z, p, q, m, n, t, r, k, w, l, ans, i, j;
string S, T;
vl A, B;
ll masu[100][100];
void solve() {
    vl tate(100, 0), yoko(100, 0);

    rep(i, h) {
        a = 0;
        rep(j, w) {
            if(masu[i][j])
                a++;
        }

        if(a == 0)
            yoko[i] = 1;
    }

    rep(i, w) {
        a = 0;
        rep(j, h) {
            if(masu[j][i])
                a++;
        }

        if(a == 0)
            tate[i] = 1;
    }

    rep(i, h) {
        rep(j, w) {
            if(tate[j] == 0 && yoko[i] == 0) {
                cout << (masu[i][j] ? "#" : ".");
            }
        }
        if(yoko[i] == 0)
            cout << endl;
    }
}
int main() {
    // cout<<fixed<<setprecision(15);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i, h) {
        cin >> S;
        rep(j, w) {
            if(S[j] == '#') {
                masu[i][j] = 1;
            } else
                masu[i][j] = 0;
        }
    }
    solve();
}