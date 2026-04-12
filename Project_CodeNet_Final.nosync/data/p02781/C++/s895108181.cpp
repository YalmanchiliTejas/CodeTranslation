#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define int long long
#ifdef DEBUG
std::ostream& dout = cout;
#else
stringstream dout;
#endif
template<typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
	in >> p.first >> p.second;
	return in;
}
signed main(signed argc, char* argv[]) {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	const int MOD = 1e9 + 7;
	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(k+1, vector<int>(2, 0)));
	dp[0][0][1] = 1;
	rep(i, s.size()) {
		rep(j, k+1) {
			int it = s[i] - '0';
			//0
			dp[i + 1][j][0] += dp[i][j][0];
			if (it == 0) {
			    //0-true
				dp[i + 1][j][1] += dp[i][j][1];
			}
			else{
			    //0-false
			    dp[i+1][j][0]+=dp[i][j][1];
			    if(j){
			        //n-true
			        dp[i+1][j][1]+=dp[i][j-1][1];
			        dp[i+1][j][0]+=dp[i][j-1][1]*(it-1);
			    }
			}
			if(j){
			    dp[i+1][j][0]+=dp[i][j-1][0]*9;
			}
		}
	}
	cout<<dp[s.size()][k][1]+dp[s.size()][k][0]<<endl;
}
