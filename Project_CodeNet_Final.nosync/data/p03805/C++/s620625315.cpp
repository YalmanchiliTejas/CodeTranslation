//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

int N, M;
bool G[10][10];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	rep(i, 0, 10)rep(j, 0, 10)G[i][j] = false;

	cin >> N >> M;
	int a, b;
	rep(i, 0, M)
	{
		cin >> a >> b;
		a--, b--;
		G[a][b] = true;
		G[b][a] = true;
	}

	vector<int> v;
	rep(i, 0, N)v.push_back(i);

	int ans = 0;
	do {
		if (v[0] != 0)continue;
		bool ok = true;
		rep(i, 0, N - 1)
		{
			if (!G[v[i]][v[i + 1]])ok = false;
		}
		if (ok)ans++;
	} while (next_permutation(all(v)));

	cout << ans << endl;

	return 0;
}