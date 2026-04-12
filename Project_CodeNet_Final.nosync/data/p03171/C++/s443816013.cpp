#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <stack>

#define pb push_back
#define ins insert
#define pob pop_back
#define er erase
#define emp empty
#define f first
#define s second
#define ff f.f
#define fs f.s
#define sf s.f
#define ss s.s
#define var auto

using namespace std;
template<typename  T>
using s = set<T>;
template<typename T>
using  v = vector<T>;
template<typename T1, typename  T2>
using p = pair < T1, T2>;
typedef long long ll;
typedef p<int, int> pii;
typedef v<int> vi;
typedef v<pii> vpii;
typedef s<int> si;
typedef s<pii> spii;


const int Max = 3e3 + 100;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, k;
ll dp[Max][Max];
ll A[Max];
ll ps[Max];

ll CALC(int i, int j)
{
	if (dp[i][j] == -1)
	{
		ll opVal1 = CALC(i + 1, j);
		ll opVal2 = CALC(i, j - 1);

		dp[i][j] = max(ps[j] - ps[i + 1] + A[i + 1] - opVal1 + A[i], ps[j - 1] - ps[i] + A[i] - opVal2 + A[j]);
	}
	return dp[i][j];
}

int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (i > 0)
			ps[i] = ps[i - 1] + A[i];
		else
			ps[0] = A[0];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
		dp[i][i] = A[i];
	}

	cout << CALC(0, n - 1) - (ps[n - 1] - CALC(0, n - 1));
}