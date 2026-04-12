#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long a[n];
    for(int i=0 ; i<n ; i++)
    cin>>a[i];
    long long dp[n+1][n+1];
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=i ; j<n ; j++){
            if(i==j)
            dp[i][j]=a[j];
            else{
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}