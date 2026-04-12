#include <bits/stdc++.h>
#define int long long
#define zmrl(x) (int)((x).size())
#define ahen(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,x,m; cin>>n>>x>>m;
    int psum[100100]; psum[0] = 0;
    set<pii> s;
    s.insert({psum[1] = x, 1});
    for (int i=2; i<=n; i++) {
        x=x*x%m;
        if (!x) {
            cout << psum[i-1] << '\n';
            return 0;
        }
        auto it = s.lower_bound({x, 0});
        if (it->fi == x) {
            int len = i-it->se;
            int q = (n-i+1) / len, r = (n-i+1) % len;
            cout << psum[i-1] + (psum[i-1]-psum[it->se-1])*q + psum[it->se-1+r] - psum[it->se-1] << '\n';
            return 0;
        }
        psum[i] = psum[i-1] + x;
        s.insert({x, i});
    }
    cout << psum[n] << '\n';
    return 0;
}