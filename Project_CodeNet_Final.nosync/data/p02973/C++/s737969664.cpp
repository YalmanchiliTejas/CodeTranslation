#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
int a[100000];
map<int, int> m;

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        auto it = m.lower_bound(a[i]);
        if (it == m.begin()) {
            m[a[i]]++;
        } else {
            it--;
            m[(*it).first]--;
            if (m[(*it).first] == 0) m.erase(it);
            m[a[i]]++;
        }
    }
    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        ans += (*it).second;
    }
    cout << ans << endl;
}
