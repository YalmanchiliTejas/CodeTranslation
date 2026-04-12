#include<bits/stdc++.h>
using namespace std;
main(){
long long int n;
cin>>n;
long long int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
long long int dp[n][n];
memset(dp,0,sizeof(dp));

long long int csum[n];
csum[0]=arr[0];
for(int i=1;i<n;i++)csum[i]=csum[i-1]+arr[i];
for(int i=0;i<n;i++)dp[i][i]=arr[i];
for(int i=1;i<n;i++)for(int j=0;j<n-i;j++){
int a=j;
int b=j+i;
//cout<<arr[a]+((csum[b]-csum[a+1]+arr[a+1])-dp[a+1][b])<<endl;


dp[a][b]=max(arr[a]+((csum[b]-csum[a+1]+arr[a+1])-dp[a+1][b]),arr[b]+(csum[b-1] -csum[a]+arr[a])-dp[a][b-1]);



//cout<<a<<" "<<b<<" "<<dp[a][b]<<endl;
}
cout<<2*dp[0][n-1]-csum[n-1];



}
