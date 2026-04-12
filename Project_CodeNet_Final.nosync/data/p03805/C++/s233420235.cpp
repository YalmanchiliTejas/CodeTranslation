#include "bits/stdc++.h"
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
//#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
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
int main() {
	int n, m;
	cin >> n >> m;
	typedef pair <int, int>P;
	map<P, bool>mp;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		mp[P(a, b)] = true;
		mp[P(b, a)] = true;
	}
	vector<int>c(n);

	rep(i, n) {
		c[i] = i + 1;
	}
	int ans = 0;
	do {
		if (c[0] != 1)continue;
		bool flag = true;
		rep(i, n - 1) {
			if (!mp[P(c[i], c[i + 1])])flag = false;
		}
		if (flag) ans++;
	} while (next_permutation(c.begin(), c.end()));
	print(ans);
}