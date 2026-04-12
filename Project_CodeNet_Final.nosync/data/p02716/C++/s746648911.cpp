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
#include<unordered_map>
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

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	vector<map<pii, int>> memo(N);

	rep(i, 0, N)
	{
		cin >> A[i];
	}

	int ans = -INF;
	memo[0][mp(2,1)] = A[0];
	memo[1][mp(1,1)] = A[1];
	if (N <= 3)
	{
		chmax(ans, max(A[0], A[1]));
	}
	if (N > 2)
	{
		memo[2][mp(0, 1)] = A[2];
		if (N <= 3)
		{
			chmax(ans, max(A[0], A[1]));
		}
	}

	rep(i, 0, N - 1)
	{
		for (auto p : memo[i])
		{
			rep(j, 0, p.first.first + 1)
			{
				if (i + 2 + j >= N)break;
				if (memo[i + 2 + j].find(mp(p.first.first - j, p.first.second + 1)) == memo[i + 2 + j].end())
				{
					memo[i + 2 + j][mp(p.first.first - j, p.first.second + 1)] = p.second + A[i + 2 + j];
				}
				else
				{
					chmax(memo[i + 2 + j][mp(p.first.first - j, p.first.second + 1)], p.second + A[i + 2 + j]);
				}
				if (p.first.second + 1 == N / 2)
				{
					chmax(ans, p.second + A[i + 2 + j]);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}