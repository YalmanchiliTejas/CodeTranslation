#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> B(N);
    rep(i,N) B[i] = A[i]/N;
    ll left = -1, right = 1e18;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2LL;
        ll cnt = 0;
        rep(i,N) {
            if (A[i] + mid < N) continue;
            cnt += (A[i]+mid+1LL)/(N+1LL);
        }
        if (cnt > mid) left = mid;
        else right = mid;
    }

    for (ll i = max(0LL, right - 100000LL); i <= right + 100000LL; i++) {
        ll cnt = 0;
        rep(j,N) {
            if (A[j] + i < N) continue;
            cnt += (A[j]+i+1LL)/(N+1LL);    
        }
        if (cnt == i) {
            cout << i << endl;
            return 0; 
        }
    }
}