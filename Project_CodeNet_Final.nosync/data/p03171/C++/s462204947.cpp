#include<bits/stdc++.h>
using namespace std;
#define int long long
//vector<pair<int,int>>g[100050];
#define pi pair<int,int>
#define pb push_back
#define f first
#define s second
#define inf (int)1e10
int dp[3333][3333];
int a[3333];
int ok(int l ,int r)
{
    if(l>r)return 0;
    if(l==r)return a[l];
    if(dp[l][r]!=-inf)return dp[l][r];
    return(dp[l][r] = max(a[l]-ok(l+1,r),a[r]-ok(l,r-1)));
   
}

void solve()
{
 int n;
 cin >>n; 
  
  for(int i=0;i<n;i++)cin >> a[i];

  cout<<ok(0,n-1)<<"\n";


}

int32_t main()
{
    int t=1;

    while(t--)
    {
         for(int i=0;i<3333;i++)
        for(int j=0;j<3333;j++)
          dp[i][j]=-inf;
        solve();
    }
}
