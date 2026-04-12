#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n';

int n, a;
deque <int> v;
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, 0, n, 1) {
        cin >> a;
        if (i % 2 == 0) {
            v.pb(a);
        }
        else {
            v.pf(a);
        }
    }
    if (n % 2 == 1) {
        reverse(all(v));
    }
    for(auto it:v) {
        cout << it << ' ';
    }
    time;
}