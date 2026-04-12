#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n; string s;
    cin >> n >> s;

    rep(i, 2) rep(j, 2) {
        vector<bool> v;
        v.push_back(i);
        v.push_back(j);

        for (int k = 1; k < n-1; k++) {
            if (v[k]) { // 羊
                if (s[k] == 'o') v.push_back(v[k-1]);
                else v.push_back(!v[k-1]);
            } else {
                if (s[k] == 'x') v.push_back(v[k-1]);
                else v.push_back(!v[k-1]);
            }
        }

        bool ok = true;
        rep(k, n) {
            int r = k + 1;
            int l = k - 1;
            if (k == 0) l = n - 1;
            if (k == n-1) r = 0;
            if (v[k]) {
                if (s[k] == 'o' && v[l] != v[r]) ok = false;
                if (s[k] == 'x' && v[l] == v[r]) ok = false;
            } else {
                if (s[k] == 'o' && v[l] == v[r]) ok = false;
                if (s[k] == 'x' && v[l] != v[r]) ok = false;
            }
        }
        if (ok) {
            // printf("(i, j) = (%d, %d)\n", i, j);
            rep(k, n) cout << (v[k] ? "S" : "W");
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
