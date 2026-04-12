#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
//No change above here

const ll maxi = 2 * 1e5 + 5;
ll mod = 5;
double pi = 3.141592653589793238;

//function for power
ll power(ll x, ll n) {
	ll res = 1;
	x %= mod;
	while (n) {
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

ll sum_digits(ll n)
{
	ll ret = 0;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

ll gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

ll max_subarray(vector<int>& v)
{
	if (v.empty())
		return 0;
	ll glob = v[0], loc = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		loc = max(v[i] + 0LL, loc + v[i]);
		glob = max(loc, glob);
	}
	return glob;
}

long long num_digits(long long x)
{
	long long ans = 0;
	while (x)
	{
		++ans;
		x /= 10;
	}
	return ans == 0 ? 1 : ans;
}

vector<int> topological_sort(vector<vector<int>>& graph, int n, vector<int>& indegree)
{
	vector<int> ans;
	stack<int> s;
	for (int i = 0; i < n; ++i)
		if (indegree[i] == 0)
			s.push(i);
	while (!s.empty())
	{
		int x = s.top();
		s.pop();
		ans.push_back(x);
		for (auto& adj : graph[x])
			if (--indegree[adj] == 0)
				s.push(adj);
	}
	return ans;
}

ll dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll p, q;
bool valid(ll i, ll j) { return i >= 1 && i <= p && j >= 1 && j <= q; }


//declare needed things here


int main()
{
	IOS;
	int x;
	cin >> x;
	if (x >= 30)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
