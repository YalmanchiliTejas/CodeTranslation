#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl "\n"     
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N=3005;

int cache[N][N][2];
int a[N];

int dp(int i,int j,int p)
{
     if(i==j)
          return (p?a[i]:-1*a[i]);
     int &ans=cache[i][j][p];
     if(ans!=-1)
          return ans;
     if(p)
          return ans=max(a[i]+dp(i+1,j,p^1),a[j]+dp(i,j-1,p^1));
     else
          return ans=min(dp(i+1,j,p^1)-a[i],dp(i,j-1,p^1)-a[j]);
}

int32_t main()
{
     memset(cache,-1,sizeof cache);
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
          cin>>a[i];
     cout<<dp(1,n,1);     
}