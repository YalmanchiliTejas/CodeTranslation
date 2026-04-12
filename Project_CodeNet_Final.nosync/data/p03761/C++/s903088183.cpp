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
	int n;
	string S, ans = "";
	map<char, int> tmp, cnt;

	for (char c = 'a'; c <= 'z'; c++) cnt[c] = 50;

	cin >> n;
	rep(i, n) {
		cin >> S;

		for (char c = 'a'; c <= 'z'; c++) tmp[c] = 0;
		rep(j, (int)S.length()) tmp[S[j]]++;
		for (char c = 'a'; c <= 'z'; c++) cnt[c] = min(cnt[c], tmp[c]);
	}

	for (char c = 'a'; c <= 'z'; c++) {
		rep(j, cnt[c]) ans.push_back(c);
	}

	sort(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}
