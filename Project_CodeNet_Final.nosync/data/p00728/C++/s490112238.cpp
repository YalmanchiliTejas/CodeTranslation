#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    REP(_, 20) {
        int n; cin >> n;
        if (n == 0) break;
        vector<int> v;
        REP(i, n) {
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        FOR(i, 1, n-1) ans += v[i];
        ans /= n - 2;
        cout << ans << endl;
    }
}
