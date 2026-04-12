#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001

int main(void) {
	string s; cin >> s;
	int d = s.size();
	vi v; rep(i,d) v.push_back(s[i]-'0');
	int k; cin >> k;
	vector<vector<vector<int>>> dp(105,vvi(5,vi(2,0)));
	dp[0][0][0] = 1;
	rep(i,d)rep(j,4)rep(r,2){
		for(int x=0; x<=(r?9:v[i]); x++)
			dp[i+1][(x!=0?(j+1):j)][r||x!=v[i]] += dp[i][j][r];
	}
	ll ans = dp[d][k][0] + dp[d][k][1];
	cout << ans << endl;
}


