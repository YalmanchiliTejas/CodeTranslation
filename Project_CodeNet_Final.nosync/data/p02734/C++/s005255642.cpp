#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 998244353;
ll dp[4000][4000];
ll N, S;
vector<ll> A;
ll ans;

int main() {
    cin >> N >> S;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        dp[i+1][A[i]] += i+1;
        for(ll j = 0; j <= S; j++) {
            dp[i+1][j] += dp[i][j];
            if(j+A[i] <= S) dp[i+1][j+A[i]] += dp[i][j];
        }
        for(int j = 0; j <= S; j++) {
            dp[i+1][j] %= mod;
        }
        ans += dp[i+1][S];
        //cerr << i << " " << dp[i+1][S] << endl;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}