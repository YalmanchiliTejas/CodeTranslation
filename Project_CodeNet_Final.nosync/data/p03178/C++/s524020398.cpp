// You either die a hero, or you live long enough to see yourself become the villain.

/**
 *   author:  Blind_is_love
 *   created: 21.12.2019, 22:13
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
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

#define endl "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) {cout << name[x] << " ";} cout << endl;
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
#define int ll

typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

const ll MOD = 1000000007;
const ll MAX = 10005;
const double PI = 3.1415926;
const ll INF = 1e18;
const double EPS = 1e-5;

string k;
int d, n;
int dp[MAX][101][2];

int solve(int i, int rem, bool small) {
	if (i == n) {
		return (rem == 0);
	}
	if (dp[i][rem][small] != -1) return dp[i][rem][small];
	int count = 0;
	if (small) {
		for(int j = 0; j < 10; ++j) {
			count += solve(i + 1, (rem + j) % d, small);
			count %= MOD;
		}
	} else {
		int j;
		for(j = 0; j < (int)(k[i] - '0'); ++j) {
			count += solve(i + 1, (rem + j) % d, true);
			count %= MOD;
		}
		count += solve(i + 1, (rem + j) % d, false);
		count %= MOD;
	}
	return dp[i][rem][small] = count;
}


signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	clock_t t1, t2;
	t1 = clock();
	memset(dp, -1, sizeof(dp));
	cin >> k >> d;
	n = k.size();
	cout << (solve(0, 0, false) - 1 + MOD) % MOD << endl;
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(long double)CLOCKS_PER_SEC << endl;
	return 0;
}
