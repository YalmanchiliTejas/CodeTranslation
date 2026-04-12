#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
const int N=1e9+7;
#define int long long
#define double long double

int32_t main()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
 IOS;
int n;
cin>>n;
int a[n];
for (int i = 0; i < n; ++i)
{
	/* code */cin>>a[i];
}
int dp[n];
dp[0]=a[0];
for (int i = 1; i < n; ++i)
{
	dp[i]=(dp[i-1]+a[i])%N;
}
int s=0;
for (int i = n-1; i>=1; i--)
{
	s+=(a[i]%N*dp[i-1]%N)%N;
}
cout<<s%N;


 	



  
 




  
return 0;
}
