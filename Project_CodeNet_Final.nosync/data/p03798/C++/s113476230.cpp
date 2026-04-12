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

int N;
string S;
int cnt[100010];

bool func()
{
	rep(i, 1, N)
	{
		if (cnt[i] > 0)
		{
			if (S[i] == 'o')
			{
				if (cnt[(i - 1 + N) % N] > 0)
				{
					cnt[(i + 1) % N]++;
				}
				else
				{
					cnt[(i + 1) % N]--;
				}
			}
			else
			{
				if (cnt[(i - 1 + N) % N] > 0)
				{
					cnt[(i + 1) % N]--;
				}
				else
				{
					cnt[(i + 1) % N]++;
				}
			}
		}
		else
		{
			if (S[i] == 'o')
			{
				if (cnt[(i - 1 + N) % N] > 0)
				{
					cnt[(i + 1) % N]--;
				}
				else
				{
					cnt[(i + 1) % N]++;
				}
			}
			else
			{
				if (cnt[(i - 1 + N) % N] > 0)
				{
					cnt[(i + 1) % N]++;
				}
				else
				{
					cnt[(i + 1) % N]--;
				}
			}
		}

		if (cnt[(i + 1) % N] == 0)
		{
			return false;
		}
	}

	rep(i, 0, N)
	{
		if (cnt[i] > 0)cout << 'S';
		else cout << 'W';
	}
	cout << endl;
	return true;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	
	if (S[0] == 'o')
	{
		fill(cnt, cnt + N, 0);
		cnt[0] = 1;
		cnt[N - 1] = cnt[1] = 1;
		if (func())return 0;
		
		fill(cnt, cnt + N, 0);
		cnt[0] = 1;
		cnt[N - 1] = cnt[1] = -1;
		if (func())return 0;

		fill(cnt, cnt + N, 0);
		cnt[0] = -1;
		cnt[N - 1] = 1, cnt[1] = -1;
		if (func())return 0;

		fill(cnt, cnt + N, 0);
		cnt[0] = -1;
		cnt[N - 1] = -1, cnt[1] = 1;
		if (func())return 0;
	}
	else
	{
		fill(cnt, cnt + N, 0);
		cnt[0] = -1;
		cnt[N - 1] = cnt[1] = 1;
		if (func())return 0;

		fill(cnt, cnt + N, 0);
		cnt[0] = -1;
		cnt[N - 1] = cnt[1] = -1;
		if (func())return 0;

		fill(cnt, cnt + N, 0);
		cnt[0] = 1;
		cnt[N - 1] = 1, cnt[1] = -1;
		if (func())return 0;

		fill(cnt, cnt + N, 0);
		cnt[0] = 1;
		cnt[N - 1] = -1, cnt[1] = 1;
		if (func())return 0;
	}

	cout << -1 << endl;

	return 0;
}