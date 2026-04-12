#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

ll dp[105][5][3];

int main(){
    string s;
    int K;
    cin >> s >> K;
    dp[0][0][0] = 1;
    for(int i=1;i<=s.size();i++){
        int sd = s[i-1] - '0';
        rep(j,K+1)rep(d,10){
            if(d==0){
                if(d < sd){
                    dp[i][j][1] += dp[i-1][j][0];
                }else if(d==sd){
                    dp[i][j][0] += dp[i-1][j][0];
                }
                dp[i][j][1] += dp[i-1][j][1];
            }else{
                if(d < sd){
                    if(j>0) dp[i][j][1] += dp[i-1][j-1][0];
                }else if(d==sd){
                    if(j>0) dp[i][j][0] += dp[i-1][j-1][0];
                }
                if(j>0) dp[i][j][1] += dp[i-1][j-1][1];
            }
        }
    }
    cout << dp[s.size()][K][0] + dp[s.size()][K][1] << endl;
    return 0;
}