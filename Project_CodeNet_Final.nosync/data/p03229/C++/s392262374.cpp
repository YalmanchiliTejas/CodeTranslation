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
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int A[100010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[100010];
	rep(i, 0, N)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	int ans[2] = { 0 };
	pair<int, int> ps[2];
	ps[0] = mp(0, N - 1);
	ps[1] = mp(0, N - 1);
	ans[0] = A[N / 2];
	ans[1] = -A[N / 2];
	rep(i, 1, N)
	{
		int t = 2;
		if (i == N - 1)
		{
			t = 1;
		}
		if (i % 2 == 1)
		{
			ans[0] -= t * A[ps[0].first];
			ps[0].first++;
			ans[1] += t * A[ps[1].second];
			ps[1].second--;
		}
		else
		{
			ans[0] += t * A[ps[0].second];
			ps[0].second--;
			ans[1] -= t * A[ps[1].first];
			ps[1].first++;
		}
	}

	cout << max(ans[0],ans[1]) << endl;

	return 0;
}