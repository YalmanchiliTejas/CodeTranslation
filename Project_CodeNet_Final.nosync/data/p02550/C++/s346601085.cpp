#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
	template <class Arg1, class... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args) {
		const char* sep = strchr(names + 1, ',');
		cerr.write(names, sep - names) << " : " << arg1 << "  ";
		__f(sep + 1, args...);
	}
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("popcnt")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<char,int> pci;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
 


#define pb push_back
 
// order_of_key (k), find_by_order(k)
#define fi first
#define se second
#define input_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {cin>>a[i];}
#define debug_arr(a,n) {{for(__typeof (n) i=0; i<n; ++i) {cout<<a[i]<<" ";}cout<<"\n";}}
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll> ,greater<ll>>
#define initialise(a, x) memset(a, x, sizeof(a))
#define endl '\n'
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX 1000020
#define maxn 200005
#define eps 0.0000001

const ll mod=998244353;
const ll inf=1e18+2;

#define int ll

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n,x,m;
	cin>>n>>x>>m;

	set<int> st;
	st.insert(x);

	vector<int> v;

	int ans=x;
	int now=x;
	v.pb(x);

	while(v.size()<n)
	{
		now*=now;
		now%=m;
		if(now==0) break;
		else if(st.find(now)!=st.end()) break;
		ans+=now;
		v.pb(now);
		st.insert(now);
	}
	
	if(now==0 or v.size()==n) cout<<ans<<'\n';
	else
	{

		int indx=0;
		while(indx<v.size() and v[indx]!=now) indx++;

		n-=indx;

		int left=v.size()-indx;

		int tans=0;

		for(int j=indx;j<v.size();j++) tans+=v[j];

		int times=n/left;

		times--;

		ans+=tans*times;

		if(n%left)
		{
			times=n%left;

			while(times--)
			{
				ans+=v[indx];
				indx++;
			}
		}

		cout<<ans<<'\n';

	}



	
	

	return 0;
}