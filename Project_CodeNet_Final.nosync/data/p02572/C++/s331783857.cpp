#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

// Use g++ compiler for this include to work.
#include <bits/stdc++.h>

using namespace std;

// Constants 
#define INF 1e18
#define EPsecond 1e-9
#define MOD 1000000007
 
// // for using in pairs
// #define first first
// #define second second
 
// Macros
#define all(x) begin(x), end(x)
 
// aliases
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;

// Temporary macro.
#define int long long

// Operator overloads.
/**
 * The type of element in the vector should have overload for << operator with ostream. 
 */
template<typename T>
ostream& operator<<(ostream &stream, vector<T> v)
{
	for (const auto &it : v)
		stream << it << " ";
	return stream;
}

/**
 * Both types in the pair should have overload for << operator with ostream. 
 */
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, pair<T1, T2> p)
{
	ostream << p.first << " " << p.second;
	return ostream;
}

// Utility functions.
void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

///////////////////////////////////////////////////////////////////////

void solve(int tc)
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int suff[n];
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		suff[i] = suff[i + 1] + a[i];
		suff[i] %= MOD;
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++)
	{
		ans += (a[i] * suff[i + 1]);
		ans %= MOD;
	}

	cout << ans ;
}	

int32_t main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;		
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}

	return 0;
}
