#include<bits/stdc++.h>
using namespace std;

long long dp[3001][3001];

int main(){
    int n;cin>>n;
    long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=a[i];
            }
            else{
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1];

}
