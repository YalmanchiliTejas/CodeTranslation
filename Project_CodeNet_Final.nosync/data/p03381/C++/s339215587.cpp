#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
//#define X first
#define Y second
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1000000007;
const LL LINF = 1LL * INF * INF;
const LL mod = 1000000007;
const LL MAX = 200047;

int A[MAX], X[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int n;
	cin >> n;
	FOR(i, 1, n + 1)
	{
		cin >> A[i];
		X[i] = A[i];
	}
	sort(X + 1, X + n + 1);
	FOR(i, 1, n + 1)
	{
		int j = lower_bound(X + 1, X + n + 1, A[i]) - X;
		if (n / 2 < j)
			cout << X[n / 2] << '\n';
		else
			cout << X[n / 2 + 1] << '\n';
	}
	return 0;
}