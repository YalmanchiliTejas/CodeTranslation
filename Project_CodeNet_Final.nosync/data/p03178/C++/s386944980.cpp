#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

ll mod = 1e9 + 7;
ll dp[10005][120][2];
string K;
int D;

int main() {
    cin >> K;
    cin >> D;
    int N = K.length();
    rep(dig,N+1){
        rep(d, D){
            rep(isless, 2){
                dp[dig][d][isless] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    rep(dig,N){
        rep(d, D){
            rep(isless, 2){
                int c = K[dig] - '0';
                rep(nxt, 10){
                    if (c > nxt) {
                        dp[dig+1][(d+nxt) % D][1] += dp[dig][d][isless];
                        dp[dig+1][(d+nxt) % D][1] %= mod;
                        if (dp[dig+1][(d+nxt) % D][1] < 0) dp[dig+1][(d+nxt) % D][1] += mod;
                    } else if (c == nxt) {
                        dp[dig+1][(d+nxt) % D][isless] += dp[dig][d][isless];
                        dp[dig+1][(d+nxt) % D][isless] %= mod;
                        if (dp[dig+1][(d+nxt) % D][isless] < 0) dp[dig+1][(d+nxt) % D][isless] += mod;
                    } else {
                        if (isless) {
                            dp[dig+1][(d+nxt) % D][isless] += dp[dig][d][isless];
                            dp[dig+1][(d+nxt) % D][isless] %= mod;
                            if (dp[dig+1][(d+nxt) % D][isless] < 0) dp[dig+1][(d+nxt) % D][isless] += mod;
                        }
                    }
                }
            }
        }
    }
    ll ans = (dp[N][0][0] + dp[N][0][1] - 1) % mod;
    if (ans < 0) ans += mod;

    cout << ans << endl;
}