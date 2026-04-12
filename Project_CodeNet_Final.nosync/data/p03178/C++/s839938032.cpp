#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll dp[10100][105][2];

int main(){
	int D;
	string s;
	cin >> s >> D;
	int N = s.size();
	rep(i,10100)rep(j,105)rep(k,2)dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	rep(i,N)rep(j,D)rep(k,2){
		int nd = s[i]-'0';
		rep(d,10){
			int ni = i+1, nj = j, nk = k;
			nj = (j+d) % D;
			if(k == 0){
				if(nd < d)continue;
				if(nd > d)nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
			dp[ni][nj][nk] %= MOD;
		}
	}
	ll ans = (dp[N][0][0] + dp[N][0][1])%MOD - 1;
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}
