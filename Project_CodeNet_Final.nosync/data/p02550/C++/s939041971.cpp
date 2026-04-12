	#include<bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp> 
	#include <ext/pb_ds/tree_policy.hpp> 
	using namespace __gnu_pbds;
	using namespace std;
	 
	#define ff                  first
	#define ss                  second
	#define endl                "\n"
	#define loop(i,s,e)         for(int i=s;i<e;i++)
	#define int                 long long
	#define vi                  vector<int> 
	#define S(v)                sort(v.begin(),v.end())
	#define RS(v)               sort(v.rbegin(),v.rend())
	#define R(v)                reverse(v.begin(),v.end())
	#define mxpq(T)             priority_queue <T>
	#define mnpq(T)             priority_queue<T,vector<T>,greater<T>>
	#define prv(v)              for(auto &x : v)cout << x << " ";
	#define piirv(v)            for(auto &x : v)cout << x.ff << " " << x.ss << endl;
	#define prvv(v)             for(auto &x : v)for(auto &y : x.ss)cout << y << " ";
	#define mp                  make_pair
	#define pii                 pair<int,int>
	#define mset(a,f)           memset(a , f , sizeof(a))
	#define pb                  push_back
	#define inf                 INT_MAX
	#define INF                 LLONG_MAX
	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
	 
	const int N = 2e6 + 6;
	const int M = 1e9+7;
	int A[N];
	int m;
	vector<int> vec;

	map<int,int> mmp;

	int id;

	void dfs(int x,int cnt)
	{
		if(mmp.count(x))
		{
			id = mmp[x]-1;
			return;
		}
		vec.pb(x);
		mmp[x] = cnt;
		int rt = (x*x)%m;
		dfs(rt,cnt+1);
	}

	void solve()
	{
		int n , x;
		cin >> n >> x >> m;
		x %= m;
		// cout << x;
		// return;
		dfs(x,1);

		int len = mmp.size();
		int len1 = len;
		// cout << len;return;

		// cout << vec[len-1] << " ";

		// if(x == 1)
		// {
		// 	cout << n;
		// 	return;
		// }

		if(n <= len)
		{
			int sum = 0;
			loop(i,0,n)sum += vec[i];
			cout << sum;
		}
		else 
		{
			int sum = 0;
			loop(i,0,len)sum += vec[i];
			n -= len;
			len -= id;
			if(len <= 1)
			{
				sum += (vec[vec.size()-1]*(n-vec.size()+1));
				cout << sum;
				return;
			}
			int rt = n/len;
			int sum1 = 0;
			loop(i,id,id+len)sum1 += vec[i];
			sum1 *= rt;
			int kt = n%len;
			int sum3= 0;
			loop(i,id,id+kt)sum3 += vec[i];
			cout << sum+sum1+sum3;
		}

	}			
	 
	int32_t main()
	{
	 
	cout<<fixed<<setprecision(16);
	 
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	 	
	 
	 	int t = 1;
	 	// cin >> t;
	 	while(t--)solve();
	  
	}