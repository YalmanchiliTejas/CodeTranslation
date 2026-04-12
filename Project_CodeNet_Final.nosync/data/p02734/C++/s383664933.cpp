// #include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define trace(x) cerr << #x << ": " << x << " " << endl;
 
typedef int64_t ll;
 
#define endl '\n'
#define int ll
ll mod=998244353;
ll mod1=1e9+5;
 
ll power(ll a,ll b)
{
    if(b==0) return 1;
    else if(b%2==0)
        return power((((a%mod)*(a%mod))%mod),b/2)%mod;
    else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
}
	 
 //using namespace __gnu_pbds;
 //#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
//erase,insert same as normal set
// mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count()); for randomized solution


int32_t main()
{
    IOS
   
	
	int n,s;
	cin>>n>>s;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	int dp[n+1][s+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]++;
	for(int i=1;i<=n;i++)
	{
		int sum=0,in=-1;
		for(int j=0;j<=s;j++)
			dp[i][j]=dp[i-1][j];
		dp[i][0]++;
		for(int j=a[i];j<=s;j++)
		{
			dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=mod;
		}
		ans+=dp[i][s];
		ans%=mod;
	}
	cout<<ans;
}       