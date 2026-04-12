#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int                     long long int
#define ld                      long double
#define pb                      push_back
#define MOD                     1000000007
#define inf                     3e18
#define vi                      vector<int>
#define vld                     vector<ld>
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define fi                      first
#define se                      second
#define fastIO                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
		//order_of_key (k) : Number of items strictly smaller than k .
		//find_by_order(k) : K-th element in a set (counting from zero) (returns an iterator)           


void inp_out()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif
}

int32_t main()
{
	fastIO
	inp_out();
	int n; 
	cin >> n; 
	vi a(n); 
	int total = 0; 
	for(int i = 0; i < n; ++ i)
	{
		cin >> a[i]; 
		total += a[i]; 
		total %= MOD; 
	}
	int ans = 0; 

	for(int i = 0; i < n; ++ i)
	{
		total -= a[i]; 
		total %= MOD; 
		total += MOD; 
		total %= MOD; 
		ans += (total * a[i]);
		ans %= MOD;  
	}

	cout << ans; 

	return 0;
}