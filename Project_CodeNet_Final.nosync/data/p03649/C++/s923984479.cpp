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
    ll ans = 0;
    if (A[0] <= N*N) {
        if (A[0] >= N) {
        while (true) {
            bool ok = true;
            rep(i,N) {
                if (i) A[i]++;
                else A[i] -= N;
                if (A[i] >= N) ok = false;
            }
            ans++;
            if (ok) break;
            sort(all(A));
            reverse(all(A));
        }
    }
    }
    for (int i = 1; i < N; i++) {
        if (A[0] < N) break;
        ll val = A[0] - A[i];
        ll cnt = val/(N+1);
        ans += cnt*i;
        rep(j,N) {
            if (j < i) A[j] -= cnt*(N+1-i);
            else A[j] += cnt*i;
        }
        //sort(all(A));
        //reverse(all(A));
    }
    ll K = A[0];
    ans += max(K-3*N,0LL)*N;
    rep(i,N) A[i] -= max(K-3*N,0LL);
    if (A[0] >= N) {
        while (true) {
            bool ok = true;
            rep(i,N) {
                if (i) A[i]++;
                else A[i] -= N;
                if (A[i] >= N) ok = false;
            }
            ans++;
            if (ok) break;
            sort(all(A));
            reverse(all(A));
        }
    }
    cout << ans << ln;
}

