#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 2e9
#define LINF 1e18
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = 1;
    for (int i=1; i<n; i++) {
        int cnt = 0;
        rep(j, i) {
            if (h[j] <= h[i]) cnt++;
            else break;
        }
        if (cnt == i) ans++;
    }
    cout << ans << endl;
}
