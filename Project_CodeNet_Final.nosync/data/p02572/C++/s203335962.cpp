// in case of multiple test cases and N=1e5 don't intialize arrays as global except for graph vector-array
// always check whether or not you are doing mod of a negative number
// always use 1LL instead of 1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

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

vector<long long> factorial(N, 1);// initialized with 1
 
inline long long add(long long x, long long y) {
	return ((x % MOD) + (y % MOD))% MOD;
}
 
inline long long subtract(long long x, long long y) {
	x = x % MOD;
	y = y % MOD;
 
	if(x >= y) return x - y;
	else return x - y + MOD;
}
 
inline long long multiply(long long x, long long y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}
 
inline long long power(long long x, long long y) {
	long long res = 1;
	x = x % MOD;
 
	while(y > 0) {
		if(y & 1) {
			res = multiply(res, x);
		}
		y = y / 2;
		x = multiply(x, x);
	}
 
	return res;
}
 
inline long long divide(long long x, long long y) {
	return multiply(x, power(y, MOD-2));
}
 
inline long long nCr(long long n, long long r) {
	if(n < r or r < 0 or n < 0) return 0;
	return divide(factorial[n], multiply(factorial[r], factorial[n-r]));
}
 
void precompute() {
	for(int i = 1; i < N-1; i++) {
		factorial[i] = multiply(factorial[i-1], i);
	}
}

int32_t main()
{
	IOS;
	int T=1;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		int n;
		cin >> n;
		int a[n+5];
		rep(i,1,n)
			cin >> a[i];
		int suff[n+5];
		int cur = 0;
		brep(i,n,1)
		{
			cur += a[i];
			suff[i-1] = cur;
		}
		//tracearr(suff,1,n);
		int ans = 0;
		rep(i,1,n-1)
		{
			int temp = multiply(a[i],suff[i]);
			ans = add(ans,temp);
		}
		cout << ans;
	}
}