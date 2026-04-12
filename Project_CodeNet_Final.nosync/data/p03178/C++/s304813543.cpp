#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > mat;

const ll MOD = 1e9 + 7;
const ll INF = 2e15 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 1e4 + 10;
const int M = 110;

ll d[N][M][2];

void add(ll& x, ll y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

ll prec(string& s, int dd) {
    int n = s.size();
    d[0][0][1] = 1;
    fr(i, n)
        fr(j, dd + 1) {
            for (int dig = 0; dig <= 9; dig++)
                add(d[i + 1][(j + dig) % dd][0], d[i][j][0]);
            for (int dig = 0; dig < s[i] - '0'; dig++)
                add(d[i + 1][(j + dig) % dd][0], d[i][j][1]);
            add(d[i + 1][(j + s[i] - '0') % dd][1], d[i][j][1]);
        }
}

void solve() {
    string s;
    int dd;
    cin >> s >> dd;
    ll ans = 0;
    prec(s, dd);
    cout << (d[s.size()][0][0] + d[s.size()][0][1] + MOD - 1) % MOD;
}



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    solve();
}
