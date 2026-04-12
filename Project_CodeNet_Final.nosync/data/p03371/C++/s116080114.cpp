#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int A, B, C, X, Y;
	int ans = 0;

	cin >> A >> B >> C >> X >> Y;

	if (A + B > C * 2) {
		int num = min(X, Y);
		ans += C * num * 2;
		X -= num;
		Y -= num;
	}

	if (A > C * 2) ans += C * 2 * X;
	else ans += A * X;

	if (B > C * 2) ans += C * 2 * Y;
	else ans += B * Y;

	cout << ans << endl;

	return 0;
}
