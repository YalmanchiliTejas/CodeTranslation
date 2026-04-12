#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

string s;
vi sj;
int k;

int dp(int i, int j, bool b) {

	if (b) {
		if (j == sj[i])return 1;
		else return 0;
	}
	if (i == 0 || j < 0)return 0;

	int t = s[i - 1] - '0';

	return 9 * dp(i - 1, j - 1, false) + dp(i - 1, j, false) + (9 + t) / 10 * dp(i - 1, j, true) + max(t - 1, 0) * dp(i - 1, j - 1, true);

}

int main() {

	cin >> s >> k;
	sj.resize(s.size()+1);
	sj[0] = 0;
	int h = 0;
	rep(i, s.size()) {
		if (s[i] != '0')h++;
		sj[i+1] = h;
	}
	cout << dp(s.size(), k, true) + dp(s.size(), k, false) << endl;

}