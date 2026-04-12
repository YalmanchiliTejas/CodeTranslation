/****************************************

			LostMartian

****************************************/
//#pragma GCC optimize("Ofast")  
//#pragma GCC target("avx,avx2,fma") 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
using namespace std;
typedef long long ll;

template <typename Arg1>
void pn(Arg1&& arg1) {
	cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1&& arg1, Args&&... args) { 
	cout << arg1 << " "; 
	pn(args...); 
}
template <typename Arg1>
void ps(Arg1&& arg1) { 
	cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1&& arg1, Args&&... args) { 
	cout << arg1 << " "; 
	ps(args...); 
}
template <typename Arg1>
void read(Arg1&& arg1) {
	cin >> arg1; 
}
template <typename Arg1, typename... Args>
void read(Arg1&& arg1, Args&&... args) { 
	cin >> arg1; 
	read(args...); 
}

#define rep(i,m,n) for(ll i=m; i<n; i++)
#define repr(i,m,n) for(ll i=m; i>=n; i--)
#define vll vector<ll >
#define vvl vector<vector<ll > >
#define pi pair<ll, ll >
#define vpi vector<pi >
#define umap unordered_map<ll, ll >
#define pb push_back
#define mk make_pair
#define sz size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define test ll t; cin>>t; while(t--)
#define ini(a, x) memset(a, x, sizeof(a))
#define d(x) cout<<"Value of "#x" = "<<x<<"\n";
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define iAmSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
void LOCAL();
#define mod 1000000007
ll cmp (ll a, ll b) {
	return ((a%mod)+(b%mod))%mod;
}
int main()
{
	clock_t z = clock();
	//LOCAL();
	iAmSpeed
	
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n) {
		cin>>a[i];
	}

	ll sum[n+1];
	ini(sum, 0);

	for(ll i=n-1; i>=0; i--) {
		sum[i]=(sum[i+1]%mod+a[i]%mod)%mod;
	}

	// rep(i,0,n) {
	// 	ps(sum[i]);
	// }

	ll ans=0;
	for(ll i=0; i<n-1; i++) {
		ans+=((sum[i+1]%mod)*(a[i]%mod))%mod, ans%=mod;
	}

	pn(ans);


















	debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	return 0;
}
void LOCAL() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
