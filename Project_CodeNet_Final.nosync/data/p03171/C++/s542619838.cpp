#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cstdio>
#include <bitset>

using namespace std;

#define nfs ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f first
#define s second
#define m_p make_pair
#define pb push_back
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define ll long long
#define ull unsigned long long
#define ld long double
#define ef else if
#define loc(x) (x).begin(),(x).end() 
#define locR(x) (x).rbegin(),(x).rend()
#define no puts("NO")
#define yes puts("YES")
#define ex puts("-1")
#define en puts("")
#define _ cout  
#define __ <<
#define outV(v) for(int i = 0 ; i < v.size() ; i++)cout << v[i] << ' ';
#define outA(x,l,r) for(int i = l ; i < r ; i++)cout << x[i] << ' ';


const ld EPS = 1e-18;
const double DEPS = 1e-9;
const ld PI = 3.141592653589793238;
const ll MOD = 998244353;
const int N = (int)(3e5) + 1;


ll gcd(ll fx, ll fy)
{
	if (!fy) return fx;
	return gcd(fy, fx % fy);
}

inline void fill(int* ar, int sz, int val)
{
	for (int i = 0; i < sz; i++)
	{
		ar[i] = val;
	}
}

int n, a[3030];
ll dp[3001][3001][2];
bool mark[3001][3001][2];

ll dfs(int l, int r, bool t)
{
	if (l > r || r < l)return 0;
	ll& dp = ::dp[l][r][t];
	if (mark[l][r][t])return dp;
	mark[l][r][t] = 1;
	ll x = (t ? -1 : 1) * a[l] + dfs(l + 1, r, !t);
	ll y = (t ? -1 : 1) * a[r] + dfs(l, r - 1, !t);

	return dp = (!t ? max(x, y) : min(x, y));
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}

	printf("%lld", dfs(0, n - 1, 0));
}