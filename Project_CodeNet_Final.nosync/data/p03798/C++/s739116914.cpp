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

int N;
string s;
char ans[100000];

#define other(c) (c == 'S' ? 'W' : 'S')

bool correct(char first, char second)
{
	bool ret = true;

	ans[0] = first;
	ans[1] = second;

	repc(i, 1, N - 2) {
		if (ans[i] == 'S' && s[i] == 'o') ans[i + 1] = ans[i - 1];
		else if (ans[i] == 'S' && s[i] == 'x') ans[i + 1] = other(ans[i - 1]);
		else if (ans[i] == 'W' && s[i] == 'o') ans[i + 1] = other(ans[i - 1]);
		else if (ans[i] == 'W' && s[i] == 'x') ans[i + 1] = ans[i - 1];
	}

	if (ans[N - 1] == 'S' && s[N - 1] == 'o' && ans[0] != ans[N - 2]) ret = false;
	if (ans[N - 1] == 'S' && s[N - 1] == 'x' && ans[0] == ans[N - 2]) ret = false;
	if (ans[N - 1] == 'W' && s[N - 1] == 'o' && ans[0] == ans[N - 2]) ret = false;
	if (ans[N - 1] == 'W' && s[N - 1] == 'x' && ans[0] != ans[N - 2]) ret = false;

	if (ans[0] == 'S' && s[0] == 'o' && ans[1] != ans[N - 1]) ret = false;
	if (ans[0] == 'S' && s[0] == 'x' && ans[1] == ans[N - 1]) ret = false;
	if (ans[0] == 'W' && s[0] == 'o' && ans[1] == ans[N - 1]) ret = false;
	if (ans[0] == 'W' && s[0] == 'x' && ans[1] != ans[N - 1]) ret = false;

	return ret;
}

int main()
{
	cin >> N >> s;

	if (correct('S', 'S')) {}
	else if (correct('S', 'W')) {}
	else if (correct('W', 'S')) {}
	else if (correct('W', 'W')) {}
	else {
		cout << -1 << endl;
		return 0;
	}

	rep(i, N) printf("%c", ans[i]);
	putchar('\n');

	return 0;
}
