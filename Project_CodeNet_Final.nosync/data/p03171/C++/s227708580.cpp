#include<bits/stdc++.h>
using namespace std;

long long int dp[3010][3010];
int main(){
    long long int N;
    cin >> N;
    long long int i,j;
    long long int a[N];
    for(i=0;i<N;i++)cin >> a[i];
    for(i=1;i<N+1;i++){//長さでループ
        for(j=0;j<N+1-i;j++){
            if((N-i)%2==0)dp[j][i+j]=max(dp[j][j+i-1]+a[i+j-1],dp[j+1][i+j]+a[j]);
            else dp[j][i+j]=min(dp[j][j+i-1]-a[i+j-1],dp[j+1][i+j]-a[j]);
        }
    }
    cout << dp[0][N] << endl;
}