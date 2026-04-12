#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    string K;
    cin>>K;
    int d;
    cin>>d;
    vector<int>n;
    for(int i=0;i<K.size();i++)n.push_back(K[i]-'0');
    int s=n.size();
    long long dp[s][d][2]={};//dp[i][j][k]:i桁見て、mod d=jで、10方向遷移が(k=0:出来る、1:出来ない)
    for(int i=0;i<n[0];i++)dp[0][i%d][0]++;
    dp[0][n[0]%d][1]++;
    for(int i=0;i<s-1;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<=9;k++){//10方向遷移が可能
                dp[i+1][(j+k)%d][0]+=dp[i][j][0]%mod;
            }
            for(int k=0;k<n[i+1];k++){//10方向遷移が不可能
                dp[i+1][(j+k)%d][0]+=dp[i][j][1]%mod;
            }
            dp[i+1][(j+n[i+1])%d][1]+=dp[i][j][1]%mod;
        }
    }
    cout<<(dp[s-1][0][0]+dp[s-1][0][1]-1)%mod<<endl;
    return 0;
}