#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    string N; cin >> N;
    int K; cin >> K;
    int n = N.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(6,0)));
    dp[0][0][0] = 1;

    rep(i,n){
        rep(j,5){
            rep(k,10){
                if (k != 0){
                    dp[i+1][1][j+1] += dp[i][1][j];
                }
                else{
                    dp[i+1][1][j] += dp[i][1][j];
                }
            }

            int num = N[i]-'0';

            rep(k,num){
                if (k != 0){
                    dp[i+1][1][j+1] += dp[i][0][j];
                }
                else{
                    dp[i+1][1][j] += dp[i][0][j];
                }
            }
            if (num != 0) dp[i+1][0][j+1] += dp[i][0][j];
            else dp[i+1][0][j] += dp[i][0][j];
        }
    }
    ll ans = 0;
    ans += dp[n][0][K];
    ans += dp[n][1][K];

    cout << ans << endl;

}