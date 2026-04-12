#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 
# define ll long long
# define pll pair<ll,ll>
# define F first
# define S second
# define pb push_back
# define ld long double
# define vll vector<ll>
# define vvll vector<vector<ll>>
# define vpll vector<pll>
# define ppll pair<pll,ll>
ll M=1000000007;
ll MAX=LONG_LONG_MAX;
template<typename T>
//using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll power(ll a,ll m,ll mod){
	ll ans=1;
	while(m){
		if(m%2){
			ans*=a;
			ans%=(mod);
		}
		a=(a*a)%(mod);
		m>>=1;
	}
	return ans;
}
ll func(int i,int j,int b,vvll &dp,vll &v)
{
   if(i==j){ 
      if(b==1)
   return v[i];
   else
   return 0;}
   if(dp[i][j]!=-1)
   return dp[i][j];
   if(b==1)
   {
      return dp[i][j]=max(func(i+1,j,2,dp,v)+v[i],func(i,j-1,2,dp,v)+v[j]);
   }
   else
   {
       return dp[i][j]=min(func(i+1,j,1,dp,v),func(i,j-1,1,dp,v));
   }
   

}
int main()
{
   int n;
   cin>>n;
   ll c=0;
   vvll dp(n,vll(n,-1));
   vll v(n);
   for(int i=0;i<n;i++){
    cin>>v[i]; c+=v[i];}
    cout<<2*func(0,n-1,1,dp,v)-c;

}