#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main(){
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        dp[0][0][0] = 1;

        for(int i=1;i<=n;i++){
                int sd = s[i-1] - '0';
                rep(cnt,k+1){
                        rep(d,10){
                                if(d ==0){
                                        if(sd ==0){
                                                dp[i][cnt][0] += dp[i-1][cnt][0];
                                                dp[i][cnt][1] += dp[i-1][cnt][1];
                                        }else{
                                                dp[i][cnt][1] += dp[i-1][cnt][0] + dp[i-1][cnt][1];
                                        }
                                }
                                else if(d < sd && cnt > 0){
                                        dp[i][cnt][1] += dp[i-1][cnt-1][0] + dp[i-1][cnt-1][1];
                                }
                                else if(d == sd && cnt > 0){
                                        dp[i][cnt][0] += dp[i-1][cnt-1][0];
                                        dp[i][cnt][1] += dp[i-1][cnt-1][1];
                                }
                                else if(d > sd && cnt > 0){
                                        dp[i][cnt][1] += dp[i-1][cnt-1][1];
                                }
                        }
                }
        }

        /*rep(i,n+1){
                rep(j,k+1){
                        rep(p,2){
                                cout << dp[i][j][p] << " ";
                        }
                        cout << " ";
                }
                cout << endl;
        }*/

        cout << dp[n][k][0] + dp[n][k][1] << endl;
        return 0;
}




