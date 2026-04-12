#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

signed main(void) {
	int n;
	cin >> n;
	vector<string>s(n);
	map<char, int>ansmp;
	rep(i, n) {
		cin >> s[i];
	}
	rep(j, s[0].size()) {
		ansmp[s[0][j]]++;
	}
	rep1(i, n) {
		map<char, int>tmpmp;
		rep(j, s[i].size()) {
			tmpmp[s[i][j]]++;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			ansmp[c] = min(ansmp[c], tmpmp[c]);
		}
	}
	string ans;
	for (char c = 'a'; c <= 'z'; c++) {
		rep(i, ansmp[c]) {
			ans += c;
		}
	}
	println(ans);
}