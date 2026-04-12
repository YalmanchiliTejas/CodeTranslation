#include<bits/stdc++.h>

using namespace std;


long long dp[3000][3000][2];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<long long> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    
    // for(int i=0;i<3000;i++){
    //     for(int k=0;k<3000;k++){
    //         dp[i][k][0]=dp[i][k][1]=0;
    //     }
    // }

    for(int i=0;i<n;i++){
        dp[i][i][1]=A[i];
        dp[i][i][0]=-A[i];
    }

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(i>=j){
                continue;
            }
            dp[i][j][0]=min(dp[i][j-1][1]-A[j], dp[i+1][j][1]-A[i]);
            dp[i][j][1]=max(dp[i][j-1][0]+A[j], dp[i+1][j][0]+A[i]);
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j][1]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[0][n-1][1]<<endl;
}