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

	int N;
	cin >> N;
	vector<ull> S(N), T(N), U(N), V(N);
	rep(i, 0, N)cin >> S[i];
	rep(i, 0, N)cin >> T[i];
	rep(i, 0, N)cin >> U[i];
	rep(i, 0, N)cin >> V[i];

	vector<vector<ull>> A(N, vector<ull>(N, 0));

	rep(k, 0, 64)
	{
		vector<vector<int>> RCNT(N, vector<int>(2, 0));
		vector<vector<int>> CCNT(N, vector<int>(2, 0));
		vector<vector<bool>> USED(N, vector<bool>(N, false));

		rep(i, 0, N)
		{
			rep(j, 0, N)
			{
				if (S[i] == 0 && ((U[i] >> k) & 1))
				{
					if (USED[i][j] && !((A[i][j] >> k) & 1))
					{
						cout << -1 << endl;
						return 0;
					}
					USED[i][j] = true;
					A[i][j] |= (1ULL << k);
					RCNT[i][1]++;
					CCNT[j][1]++;
				}
				if (S[i] == 1 && !((U[i] >> k) & 1))
				{
					if (USED[i][j] && ((A[i][j] >> k) & 1))
					{
						cout << -1 << endl;
						return 0;
					}
					USED[i][j] = true;
					RCNT[i][0]++;
					CCNT[j][0]++;
				}
			}
		}

		rep(j, 0, N)
		{
			rep(i, 0, N)
			{
				if (T[j] == 0 && ((V[j] >> k) & 1))
				{
					if (USED[i][j] && !((A[i][j] >> k) & 1))
					{
						cout << -1 << endl;
						return 0;
					}
					USED[i][j] = true;
					A[i][j] |= (1ULL << k);
					RCNT[i][1]++;
					CCNT[j][1]++;
				}
				if (T[j] == 1 && !((V[j] >> k) & 1))
				{
					if (USED[i][j] && ((A[i][j] >> k) & 1))
					{
						cout << -1 << endl;
						return 0;
					}
					USED[i][j] = true;
					RCNT[i][0]++;
					CCNT[j][0]++;
				}
			}
		}

		rep(i, 0, N)
		{
			if (S[i] == 0 && !((U[i] >> k) & 1) && RCNT[i][0] == 0)
			{
				rep(j, 0, N)
				{
					if (USED[i][j])continue;
					if (!((V[j] >> k) & 1))
					{
						USED[i][j] = true;
						RCNT[i][0]++;
						CCNT[j][0]++;
						//break;
					}
				}
			}
			if (S[i] == 1 && ((U[i] >> k) & 1) && RCNT[i][1] == 0)
			{
				rep(j, 0, N)
				{
					if (USED[i][j])continue;
					if (((V[j] >> k) & 1))
					{
						USED[i][j] = true;
						A[i][j] |= (1ULL << k);
						RCNT[i][1]++;
						CCNT[j][1]++;
						//break;
					}
				}
			}
		}
		rep(j, 0, N)
		{
			if (T[j] == 0 && !((V[j] >> k) & 1) && CCNT[j][0] == 0)
			{
				rep(i, 0, N)
				{
					if (USED[i][j])continue;
					if (!((U[i] >> k) & 1))
					{
						USED[i][j] = true;
						RCNT[i][0]++;
						CCNT[j][0]++;
						//break;
					}
				}
			}
			if (T[j] == 1 && ((V[j] >> k) & 1) && CCNT[j][1] == 0)
			{
				rep(i, 0, N)
				{
					if (USED[i][j])continue;
					if (((U[i] >> k) & 1))
					{
						USED[i][j] = true;
						A[i][j] |= (1ULL << k);
						RCNT[i][1]++;
						CCNT[j][1]++;
						//break;
					}
				}
			}
		}

		rep(i, 0, N)
		{
			if (S[i] == 0 && !((U[i] >> k) & 1) && RCNT[i][0] == 0)
			{
				bool ok = false;
				rep(j, 0, N)
				{
					if (USED[i][j])continue;
					if (!((V[j] >> k) & 1) || CCNT[j][0] < N-1)
					{
						ok = true;
						USED[i][j] = true;
						RCNT[i][0]++;
						CCNT[j][0]++;
						break;
					}
				}
				if (!ok)
				{
					cout << -1 << endl;
					return 0;
				}
			}
			if (S[i] == 1 && ((U[i] >> k) & 1) && RCNT[i][1] == 0)
			{
				bool ok = false;
				rep(j, 0, N)
				{
					if (USED[i][j])continue;
					if (((V[j] >> k) & 1) || CCNT[j][1] < N-1)
					{
						ok = true;
						USED[i][j] = true;
						A[i][j] |= (1ULL << k);
						RCNT[i][1]++;
						CCNT[j][1]++;
						break;
					}
				}
				if (!ok)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
		rep(j, 0, N)
		{
			if (T[j] == 0 && !((V[j] >> k) & 1) && CCNT[j][0] == 0)
			{
				bool ok = false;
				rep(i, 0, N)
				{
					if (USED[i][j])continue;
					if (!((U[i] >> k) & 1) || RCNT[i][0] < N-1)
					{
						ok = true;
						USED[i][j] = true;
						RCNT[i][0]++;
						CCNT[j][0]++;
						break;
					}
				}
				if (!ok)
				{
					cout << -1 << endl;
					return 0;
				}
			}
			if (T[j] == 1 && ((V[j] >> k) & 1) && CCNT[j][1] == 0)
			{
				bool ok = false;
				rep(i, 0, N)
				{
					if (USED[i][j])continue;
					if (((U[i] >> k) & 1) || RCNT[i][1] < N-1)
					{
						ok = true;
						USED[i][j] = true;
						A[i][j] |= (1ULL << k);
						RCNT[i][1]++;
						CCNT[j][1]++;
						break;
					}
				}
				if (!ok)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	rep(i, 0, N)
	{
		rep(j, 0, N)
		{
			cout << A[i][j];
			if (j == N - 1)
			{
				cout << endl;
			}
			else
			{
				cout << " ";
			}
		}
	}

	return 0;
}