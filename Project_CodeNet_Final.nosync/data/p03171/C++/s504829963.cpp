#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mk make_pair
#define pb push_back
#define vi vector<int>
#define ms(a,b)  memset(a, b, sizeof(a))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define M 1000005
int dp[3001][3001];
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x,y,z,s=0;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
    for(int i=0;i<n;i++)dp[i][i]=a[i];
    for(int i=0;i+1<n;i++)
        dp[i][i+1]=max(a[i],a[i+1]);
    for(int gap=2;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            x=dp[i+2][j],y=dp[i+1][j-1],z=dp[i][j-2];
            dp[i][j]=max(a[i] + min(x,y),a[j]+min(y,z));
        }
    }
    cout<<2*dp[0][n-1]-s;
    return 0;
}