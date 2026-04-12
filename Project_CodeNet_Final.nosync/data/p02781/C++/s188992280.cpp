#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

ll dp[110][5][2];

int main() {
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    if(s[0]-'0' == 0) {
        dp[0][0][0] = 1;
    } else {
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        dp[0][1][1] = s[0]-'0'-1;
    }
    rep(i,n-1) rep(j,K+1) rep(k,2) {
        int now = s[i+1]-'0';
        if(k == 0) {
            if(now != 0) {
                dp[i+1][j+1][k] += dp[i][j][k];
                dp[i+1][j+1][1] += dp[i][j][k]*(now-1);
                dp[i+1][j][1] += dp[i][j][k];
            } else {
                dp[i+1][j][k] += dp[i][j][k];
            }
        } else {
            dp[i+1][j+1][k] += dp[i][j][k]*9;
            dp[i+1][j][k] += dp[i][j][k];
        }
    }
    cout << dp[n-1][K][0]+dp[n-1][K][1] << endl;
}