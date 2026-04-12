//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <iterator>
#include <bitset>
#include <complex>
#include <limits>
#include <random>
#include<fstream>
#include<array>


using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

typedef unsigned long long ull;
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

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, X, M;
	cin >> N >> X >> M;

	if (N <= 1000000)
	{
		int ans = X;
		int A = X;
		rep(i, 1, N)
		{
			A = (A*A) % M;
			ans += A;
		}
		cout << ans << endl;
	}
	else
	{
		vector<int> C;
		vector<bool> USED(M, false);
		C.push_back(X);
		USED[X] = true;
		int A = X;
		rep(i, 0, M + 1)
		{
			A = (A*A) % M;
			if (USED[A])break;
			USED[A] = true;
			C.push_back(A);
		}

		int t = 0;
		rep(i, 0, M + 1)
		{
			if (C[i] == A)break;
			t++;
		}

		int ans = 0;
		rep(i, 0, SZ(C))
		{
			if (i < t)ans += C[i];
			else ans += C[i] * ((N - i + (SZ(C) - (t)) - 1) / (SZ(C) - (t)));
		}
		cout << ans << endl;
	}

	return 0;
}
