#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL);
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007

int32_t main(){
IOS;
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int dp[n+1][n+1][2];
for(int i=1;i<=n;i++)
{
    dp[i][i][0] = a[i-1];
    dp[i][i][1] = 0;
}

for(int k=1;k<=n;k++)
for(int i=0;i+k<=n;i++)
{
   
   int j = i+k;
   

if(a[i-1] + dp[i+1][j][1] - dp[i+1][j][0] >= a[j-1] + dp[i][j-1][1] - dp[i][j-1][0])
{
    dp[i][j][0] = a[i-1] + dp[i+1][j][1];
    dp[i][j][1] = dp[i+1][j][0];
}

else 
{
    dp[i][j][0] = a[j-1] + dp[i][j-1][1];
    dp[i][j][1] = dp[i][j-1][0];
}


}

cout<<dp[1][n][0] - dp[1][n][1]<<endl;

}
