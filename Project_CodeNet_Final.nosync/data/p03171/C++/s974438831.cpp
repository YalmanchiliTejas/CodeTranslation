#include<bits/stdc++.h>
#define int long long int
#define nitro ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define DEBUG false
#pragma GCC optimize "trapv"

using namespace std;

int32_t main()
{
 nitro;
 int n;
 cin>>n;
 int dp[3005][3005];
 std::vector<int> v(n);
 for(int& x:v)
 cin>>x;
 for(int l=n-1;l>=0;--l)
 {
     for(int r=l;r<n;++r)
     {
         if(l==r)
         dp[l][r]=v[l];
         else
         dp[l][r]=max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
 }
 }
 cout<<dp[0][n-1]<<'\n';
return 0;
}