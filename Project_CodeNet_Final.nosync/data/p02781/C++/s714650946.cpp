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
const ll mod = 1000000007;
ll dp[2][105][5];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    dp[0][0][0] = 1;
    ll K;
    cin >> S >> K;
    S = "#" + S;
    for(int i = 1; i < S.size(); i++) {
        for(int before = 0; before <= K; before++) {
            for(int digit = 0; digit <= 9; digit++) {
                int after = before;
                if(digit != 0) after++;
                if(char('0' + digit) < S[i]) {
                    dp[1][i][after] += dp[0][i-1][before];
                    dp[1][i][after] += dp[1][i-1][before];
                }
                if(char('0' + digit) == S[i]) {
                    dp[0][i][after] += dp[0][i-1][before];
                    dp[1][i][after] += dp[1][i-1][before];
                }
                if(char('0' + digit) > S[i]) {
                    dp[1][i][after] += dp[1][i-1][before];
                }
            }
        }
    }
    ll ans = 0;
        ans += dp[0][S.size()-1][K];
        ans += dp[1][S.size()-1][K];
    cout << ans;
    return 0;
}