#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define ln '\n'
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int l = 0, r = N-1;
        ll val = 0;
        vector<bool> visited(N);
        while (r > i and !visited[l] and !visited[r] and l != r) {
            visited[l] = visited[r] = 1;
            val += A[l] + A[r];
            chmax(ans,val);
            l += i;
            r -= i;
        }
    }

    cout << ans << ln;
}