#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
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
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;


ll dp[3005][3005];


int main() {

	int n;
	cin >> n;
	VLL a(n);
	REP(i, n)cin >> a[i];


	FOR(i, 1, n + 1) {
		REP(j, n - i + 1) {
			int k = i + j;

			if ((n - i) % 2 == 0)
				dp[j][k] = max(dp[j + 1][k] + a[j], dp[j][k - 1] + a[k - 1]);
			else
				dp[j][k] = min(dp[j + 1][k] - a[j], dp[j][k - 1] - a[k - 1]);
		}
	}

	cout << dp[0][n] << endl;


}


