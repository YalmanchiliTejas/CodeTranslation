#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define hii cout << "hii" << endl
#define int long long
#define endl '\n'
#define all(s) s.begin(), s.end()
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
 
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
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

const int N = 5e5 + 5;
const int MAX = 250000 + 5;
const int M = 1e6 + 5;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int INF = 1e15;
const int LG = 21;

int arr[N];

void solve()
{
	int n;
	cin >> n;
	int tot = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		tot += arr[i];
		tot %= mod;
	}
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		tot -= arr[i];
		tot += mod;
		tot %= mod;
		ret += arr[i] * tot;
		ret %= mod;
	}
	cout << ret << endl;
}

 
int32_t main() 
{	
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	    int t = 1;
	    // cin >> t;
	while(t--)solve();
	return 0;
}