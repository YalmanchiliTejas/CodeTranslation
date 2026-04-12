/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) {
            mat[i][j] = s[j];
        }
    }
    vector<int> cntr(m, 0), cntc(n, 0);
    forn(i, n) {
        forn(j, m) {
            cntc[i] += mat[i][j] == '.';
            cntr[j] += mat[i][j] == '.';
        }
    }
    forn(i, n) {
        if (!(cntc[i] == m)) {
            bool ok = 0;
            forn(j, m) {
                if (!(cntr[j] == n)) {
                    ok = 1;
                    cout << mat[i][j];
                }
            }
            if (ok)
                cout << endl;
        }
    }
    return 0;
}