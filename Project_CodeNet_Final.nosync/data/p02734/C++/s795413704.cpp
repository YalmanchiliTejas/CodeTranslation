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
const int MOD = 998244353;
const double EPS = 1e-9;

int DP[3010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	rep(i, 0, N)cin >> A[i];

	int ans = 0;
	rep(i, 0, N)
	{
		if (A[i] > S)continue;
		ans += DP[S-A[i]] * (N - i);
		if (A[i] == S)ans += (i + 1)*(N - i);
		ans %= MOD;
		rrep(j, 0, S)
		{
			if (j + A[i] <= S)
			{
				DP[j + A[i]] += DP[j];
				DP[j + A[i]] %= MOD;
			}
		}
		DP[A[i]] += i + 1;
		DP[A[i]] %= MOD;
	}

	cout << ans << endl;

	return 0;
}