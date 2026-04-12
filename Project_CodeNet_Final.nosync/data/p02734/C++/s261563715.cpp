#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountll
#define m_p make_pair
#define inf 1e18+1
#define eps 0.000000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>//usage rand<long long>()
T rand() {
    return uniform_int_distribution<T>()(rng);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
//////////////
auto clk=clock();
#define all(x) x.begin(),x.end()
#define se second
#define fi first
#define sz(x) ((long long)x.size())
#define int long long  
#define f80 __float128
#define pii pair<int,int>
/////////////

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n;
	cin>>n;
	int s;
	cin>>s;
	int a[n+1];
	int mo=998244353;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int dp[3001]={};
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=3000;j>=0;--j)
		{
			if(j-a[i]>=0)
				dp[j]=(dp[j]+dp[j-a[i]])%mo;
		}
		// cout<<i<<endl;
		dp[a[i]]+=i;
		dp[a[i]]%=mo;
		ans=(ans+(dp[s]))%mo;
	}
	cout<<ans;
	#ifdef ANIKET_GOYAL
		cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
	#endif
}