#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; i>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;
#define fastio cin.tie(nullptr); ios_base::sync_with_stdio(false);
#define endl '\n'
template <class T> bool updmax(T& a, T b) { if (b > a) { a = b; return true;} return false;}
template <class T> bool updmin(T& a, T b) { if (b < a) { a = b; return true;} return false;}

int main() {
    fastio;
    ll N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    vector<int> c{a.front()};
    for (int i=1; i<N; ++i) {
        auto it = lower_bound(rbegin(c), rend(c), a[i]);
        if (it == rbegin(c)) {
            c.push_back(a[i]);
        } else {
            *(--it) = a[i];
        }
    }
    cout << c.size() << endl;
}
