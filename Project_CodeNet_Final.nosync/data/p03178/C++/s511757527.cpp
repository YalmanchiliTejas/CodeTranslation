#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string s;
    int d;
    cin >> s >> d;
    vector<vector<vector<ll>>> dp(s.size()+1, vector<vector<ll>>(d, vector<ll>(2, 0)));
    dp[0][0][1] = 1;
    REP(i, s.size()){
        ll it = s[i-1] - '0';
        rep(j, d){
            rep(k, 10){
                if(k < it)dp[i][(j+k)%d][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i][(j+k)%d][0]) % mod;
                if(k == it){
                    dp[i][(j+k)%d][0] = (dp[i-1][j][0] + dp[i][(j+k)%d][0]) % mod;
                    dp[i][(j+k)%d][1] = (dp[i-1][j][1] + dp[i][(j+k)%d][1]) % mod;
                }
                if(k > it)dp[i][(j+k)%d][0] = (dp[i-1][j][0] + dp[i][(j+k)%d][0]) % mod;
            }
        }
    }
    cout << (dp[s.size()][0][0] + dp[s.size()][0][1] - 1 + mod) % mod << endl;
}   