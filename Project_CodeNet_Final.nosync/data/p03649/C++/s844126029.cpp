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
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    sort(all(A));
    reverse(all(A));
    if (A[0] < N) {
        cout << 0 << ln;
        return 0;
    }
    bool flag = true;
    ll ans = 0;
    while (flag) {
        ll cnt = 0;
        flag = false;
        rep(i,N) {
            if (i==0) {
                ll k = A[i]%N;
                cnt = (A[i]-k)/N;
                A[i] = k;
            } else {
                A[i] += cnt;
                if (A[i] >= N) flag = true;
            }
        }
        ans += cnt;
        sort(all(A));
        reverse(all(A));
    }

    cout << ans << ln;
}

