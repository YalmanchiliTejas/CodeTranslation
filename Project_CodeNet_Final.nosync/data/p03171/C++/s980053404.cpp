/*author: hyperion_1724
  date: 
*/
 
//Required Libraries
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
//Required namespaces
 
using namespace std;
using namespace __gnu_pbds;
 
//Required defines
 
#define endl '\n'
 
#define READ(X) cin>>X;
#define READV(X) long long X; cin>>X;
#define READAR(A,N) long long A[N]; for(long long i=0;i<N;i++) {cin>>A[i];}
#define rz(A,N) A.resize(N);
#define sz(X) (long long)(X.size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define trav(x,A) for(auto &x:A)
#define veci vector<int>
#define vecl vector<long long>
#define FORI(a,b,c) for(long long a=b;a<c;a++)
#define FORD(a,b,c) for(long long a=b;a>c;a--)
 
//Required typedefs
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
 
//Required Constants
 
const long long inf=(long long)1e18;
const long long MOD=(long long)(1e9+7);
const long long INIT=(long long)(5000+1);
 
//Required Functions
 
ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % MOD; 
    p = (p * p) % MOD; 
  
    return (y%2 == 0)? p : (x * p) % MOD; 
}
ll modInverse(ll a) 
{ 
   return power(a,MOD-2); 
   
}
 
//Work
 
ll dp[INIT][INIT][2]={0};
ll A[INIT]={0};
 
ll make(ll l,ll r,ll c)
{
	if (dp[l][r][c]!=-inf)
	{
		return dp[l][r][c];
	}
	if (l==r)
	{
		dp[l][r][1]=A[l];
		dp[l][r][0]=0;
	}
	else if(l<r)
	{
		if (A[l]+make(l+1,r,0) >= A[r]+make(l,r-1,0))
		{
			dp[l][r][1]=A[l]+make(l+1,r,0);
			dp[l][r][0]=make(l+1,r,1);
		}
		else
		{
			dp[l][r][1]=A[r]+make(l,r-1,0);
			dp[l][r][0]=make(l,r-1,1);
		}
	}
	return dp[l][r][c];
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
 
 
    FORI(i,0,INIT)
    {
    	FORI(j,0,INIT)
    	{
    		dp[i][j][0]=-inf;
    		dp[i][j][1]=-inf;
    	}
    }
	READV(N);
	FORI(i,1,N+1)
	{
		READ(A[i]);
	}
	ll ans=make(1,N,1)-make(1,N,0);
	cout<<ans<<endl;
 
	return 0;
}