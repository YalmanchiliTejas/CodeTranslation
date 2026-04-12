#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    deque<int> d;
    rep(i, N) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (p == 0) {
            d.push_front(a[i]);
        } else {
            d[p - 1] = a[i];
        }
    }
    int ans = d.size();
    cout << ans << endl;
}
