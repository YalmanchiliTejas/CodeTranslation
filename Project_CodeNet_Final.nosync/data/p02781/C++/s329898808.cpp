#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

LL dp[110][10][2];

int main(){
    fastcin();

    string n;
    cin >> n;
    int k;
    cin >> k;
    int m = n.size();
    dp[0][0][1] = 1;
    rep(i, m)rep(j, k+1)rep(flag, 2){
        if(flag){
            int border = n[i]-'0';
            if(border > 0){
                dp[i+1][j+1][1] += dp[i][j][1];
                dp[i+1][j+1][0] += dp[i][j][1]*(border-1);
                dp[i+1][j][0] += dp[i][j][1];
            }else{
                dp[i+1][j][1] += dp[i][j][1];
            }
        }else{
            dp[i+1][j+1][0] += dp[i][j][0]*9;
            dp[i+1][j][0] += dp[i][j][0];
        }
    }
    cout << dp[m][k][0]+dp[m][k][1] << endl;
}