#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 998244353;


int main() {

	string s;
	cin >> s;

	int k;
	cin >> k;
	if (s.size() == 1) {
		if (k == 1) {
			cout << s << endl;
		}
		else cout << 0 << endl;
		return 0;
	}


	VVLL dp(s.size(), VLL(k + 2, 0));
	VVLL b(s.size(), VLL(k + 2, false));

	dp[0][1] = (int)(s[0] - '0');
	dp[0][0] = 1;

	REP(i, s.size())dp[i][0] = 1;
	b[0][1] = true;



	REP(i, s.size() - 1) {
		dp[i][0] = 1;
		dp[i + 1][0] = 1;
		int num = (int)(s[i + 1] - '0');

		if (num == 0) {

			REP(j, k+1) {
				if (!b[i][j]) {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j + 1] += dp[i][j] * 9 + num;
				}
				else {
					b[i + 1][j] = true;
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j + 1] += (dp[i][j] - 1) * 9;
				}
			}
		}
		else {
			REP(j, k+1) {
				if (!b[i][j]) {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j + 1] += dp[i][j] * 9;
				}
				else {
					b[i + 1][j + 1] = true;
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j + 1] += (dp[i][j] - 1) * 9 + num;
				}
			}
		}
	}

	cout << dp[s.size()-1][k] << endl;

	
}