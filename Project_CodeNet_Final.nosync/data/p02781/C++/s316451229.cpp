#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int K;
    cin>>s>>K;
    int n=s.size();
    int dp[110][2][5];
    //dp[i][j][k]:i桁目まで見た時にjで未満が確定して、0でない数字の個数がk個のものの個数
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<5;k++)dp[i][j][k]=0;
        }
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<4;k++){
                int lim=j?9:s[i]-'0';
                for(int l=0;l<=lim;l++){
                    if(l!=0){
                        dp[i+1][j||l<lim][k+1]+=dp[i][j][k];
                    }else{
                        dp[i+1][j||l<lim][k]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    cout<<dp[n][0][K]+dp[n][1][K]<<endl;
}