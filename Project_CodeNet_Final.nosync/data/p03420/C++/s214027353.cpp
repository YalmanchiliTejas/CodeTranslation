#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

int main() {
    FAST_IO();
    int N, K; cin >> N >> K;
    ll ans = 0;
    if(K == 0) {
        cout << 1LL*N*N << "\n";
        return 0;
    }
    repp(b, K + 1, N) {
        // a = b*q + r (K <= r < b)
        ans += 1LL * (b - K) * ((N - b + 1) / b + 1);
        ans += max(0, N - b * ((N - b + 1) / b + 1) - K + 1);
    }
    cout << ans << "\n";
}