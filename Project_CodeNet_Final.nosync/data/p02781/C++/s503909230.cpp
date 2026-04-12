#include<bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin>>N;
    int K;
    cin>>K;
    vector<int>n;
    for(int i=0;i<N.size();i++){
        n.push_back(N[i]-'0');
    }
    int ns=n.size();
    int dp[ns][K+2][2]={};//dp[i][j][k]:i桁目まで見て、0以外がj個で、次に10方向遷移が｛k=0:出来る、k=1:出来ない｝ものの数
    dp[0][1][0]=n[0]-1;
    dp[0][1][1]=1;
    dp[0][0][0]=1;
    for(int i=0;i<ns-1;i++){
        for(int j=0;j<=K;j++){
            dp[i+1][j][0]+=dp[i][j][0];//0
            dp[i+1][j+1][0]+=dp[i][j][0]*=9;//1～9
            if(n[i+1]==0)dp[i+1][j][1]+=dp[i][j][1];//0(のみ)
            else{
                dp[i+1][j][0]+=dp[i][j][1];//0
                dp[i+1][j+1][0]+=dp[i][j][1]*(n[i+1]-1);//1～n[i+1]-1
                dp[i+1][j+1][1]+=dp[i][j][1];//n[i]
            }
        }
    }
    cout<<dp[ns-1][K][0]+dp[ns-1][K][1]<<endl;
    return 0;
}