// in case of multiple test cases and N=1e5 don't intialize arrays as global except for graph vector-array
// always check whether or not you are doing mod of a negative number
// always use 1LL instead of 1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

// using long doubles saves you from corner cases but is very time consuming
#define double      	long double
#define int         	long long
#define pb          	push_back
#define pii         	pair<int,int>
#define vi          	vector<int>
#define vii         	vector<pii>
#define mi          	map<int,int>
#define mii         	map<pii,int>
#define all(a)      	(a).begin(),(a).end()
#define sz(x)       	(int)x.size()
// just comment the line below in case of interactive problems
#define endl        	"\n"
#define repp(i,a,b) 	for(int i=a;i<b;i++)
#define rep(i,a,b) 		for(int i=a;i<=b;i++)
#define brep(i,a,b)     for(int i=a;i>=b;i--)
#define deb1(x)      	cout << #x << "=" << x << endl
#define deb2(x, y)  	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)  	cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define trace(v) 		for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
#define tracearr(a,l,r) for(int iii=l;iii<=r;iii++)cout << a[iii] << " ";cout << endl;
#define PI          	3.1415926535897932384626
#define F 				first
#define S 				second
#define clr(x,y) 		memset(x, y, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=1e5 + 5;
const int MOD=1e9 + 7;

int32_t main()
{
	//IOS;
	int T=1;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		int n,x,m;
		cin >> n >> x >> m;
		vi v;
		x = x%m;
		v.pb(x);
		mi mp;
		mp[x] = 1;
		x = x*x;
		while(1)
		{
			x = x%m;
			if(mp[x]==1)
				break;
			v.pb(x);
			mp[x] = 1;
			x = x*x;
		}
		//deb1(x);
		//trace(v);
		int c = 0;
		int ans = 0;
		while(c<n && v[c]!=x)
		{
			ans += v[c];
			c++;
		}
		int left = n - c; 
		int idx = c;
		int sz = v.size() - idx;
		//deb3(left,idx,sz);
		int fac = left/sz;
		int sum = 0;
		repp(i,idx,v.size())
		{
			sum += v[i];
		}
		ans += fac*sum;
		left -= fac*sz;
		while(left>0)
		{
			ans += v[c];
			c++;
			left--;
		}
		cout << ans;
		
		
	}
}