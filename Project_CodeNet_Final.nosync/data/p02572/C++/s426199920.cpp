#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define ld long double
#define mem(x,y) memset(x,y,sizeof x)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;

const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
/*
 * Be careful of overflow
 * Array bounds
 * Assert a!=0 when performing x/a
 * Check base condition for recursion
 * Iterator -> O(1), Element -> O(log n) while using erase
 * 1LL<<x when x>32
 * Be sure of what you are going to code (exception dp)
 * Don't try fancy tricks during contest
 * You can always make a bad round to a good enough round
 */ 

void solve()
{
	int n;
	cin>>n;
	ll val,ans=0,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		ans+=sum*val%mod;
		ans%=mod;
		sum+=val;
		sum%=mod;
	}
	cout<<ans<<'\n';
}

int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
