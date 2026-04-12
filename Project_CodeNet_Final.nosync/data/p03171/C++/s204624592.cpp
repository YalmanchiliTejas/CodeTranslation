#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[3001][3001][2];
vector<vector<int>> known(3001, vector<int>(3001, 0));
int a[3000];
int n;
int INF = -1e12+7;
void recur(int i, int k, int m){
    if(k==0){
        dp[i][k][0]=0;
        dp[i][k][1]=0;
        return;
    } 
    if(i==n){
        dp[i][k][0]=-INF;
        dp[i][k][1]=-INF;
    }
    if(!known[i+1][k-1])recur(i+1,k-1,1-m);
    if(!known[i][k-1])recur(i,k-1,1-m);
    known[i+1][k-1]=1;
    known[i][k-1]=1;
    if(m){//jiro's move
        int o1 = a[i] + dp[i+1][k-1][1];
        int o2 = a[i+k-1] + dp[i][k-1][1];
        if(o1 >= o2){
            dp[i][k][1] = o1;
            dp[i][k][0] = dp[i+1][k-1][0];
        } else {
            dp[i][k][1] = o2;
            dp[i][k][0] = dp[i][k-1][0];
        }
    } else {
        int o1 =a[i] + dp[i+1][k-1][0];
        int o2 =a[i+k-1] + dp[i][k-1][0];
        if(o1 >= o2){
            dp[i][k][0] = o1;
            dp[i][k][1] = dp[i+1][k-1][1];
        } else {
            dp[i][k][0] = o2;
            dp[i][k][1] = dp[i][k-1][1];
        }
    }
}
int32_t main() {
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    recur(0,n,0);
    cout<<dp[0][n][0] - dp[0][n][1]<<"\n";
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<"{"<<dp[i][j][0]<<","<<dp[i][j][1]<<"} ";
        }
        cout<<"\n";
    }*/
    return 0;
}