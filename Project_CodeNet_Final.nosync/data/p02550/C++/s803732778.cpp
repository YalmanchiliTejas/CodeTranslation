// One Batch Two Batch Penny and Dime

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
const int MAXN = 1e6 + 5;
const int M = 1e6 + 5;
const int mod = 998244353;
const int MOD = 998244353;
const int INF = 1e18 + 8;
const int LG = 21;

int arr[M];
int cnt[M];

void solve()
{
	int n, x, m;
	cin >> n >> x >> m;
	vector<int> v;
	v.push_back(x);
	cnt[x] = 1;
	int no = -1;
	for(int i = 1; i < n and no == -1; i++)
	{
		int now = (v[i - 1] * v[i - 1]) % m;
		if(cnt[now]) no = now;
		else v.push_back(now);
		cnt[now]++;
	}
	int sum = 0;
	if(v.size() >= n)
	{
		for(int x : v)
		{
			sum += x;
		}
		cout << sum << endl;
		return;
	}
	else
	{
		bool yep = 0;
		vector<int> cycle;
		for(int i = 0; i < v.size(); i++)
		{
			if(cnt[v[i]] == 1 and !yep)
			{
				sum += v[i];
				n--;
			}
			else
			{
				cycle.push_back(v[i]);
				yep = 1;
			}
		}
		int len = cycle.size();
		int mul = n / len;
		for(int i = 0; i < len; i++)
		{
			sum += (mul) * cycle[i];
			n -= mul;
		}
		for(int i = 0; i < n; i++)
		{
			sum += cycle[i];
		}
		cout << sum << endl;
	}

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