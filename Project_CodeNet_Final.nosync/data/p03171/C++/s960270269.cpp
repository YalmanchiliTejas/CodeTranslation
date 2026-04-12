#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")
#pragma warning( disable : 6031)
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>
#include <iomanip>
#include <limits>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define eps (1e-9)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;
typedef tuple<int, int, int> tiii;
const long long mod = 1000000007;

template<typename T>
void max_self(T& a, T b)
{
	a = max(a, b);
}

// dp[i] - TRUE if first player wins with i stones remaining

int main()
{ 
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << setprecision(18) << fixed;
	int n;
	cin >> n;
	vi a(n);
	for (int& i : a)
		cin >> i;
	vector<vector<ll>> dp(n + 1, vll(n + 1));
	for (int L = n - 1; L >= 0; L--)
	{
		for (int R = L; R < n; R++)
		{
			if (L == R)
				dp[L][R] = a[L];
			else
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			
		}
	}
	cout << dp[0][n - 1];
	return 0;
}