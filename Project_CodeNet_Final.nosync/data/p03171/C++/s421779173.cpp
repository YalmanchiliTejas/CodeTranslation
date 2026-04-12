#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[3333][3333];
bool used[3333][3333];

int main(){
	
	int n;cin >> n;
	vector<ll> v(n);
	REP(i,n)cin >> v[i];
	
	queue<pair<int,int>> q;
	REP(i,n){
		if(n % 2)dp[i][i] = v[i];
		else dp[i][i] = -v[i];
	}
	REP(i,n-1)q.push(MP(i,i+1));
	
	while(!q.empty()){
		auto now = q.front();q.pop();
		int l = now.FI;
		int r = now.SE;
		if(used[l][r])continue;
		used[l][r] = true;		
		if(((r - l + 1) % 2) == (n % 2)){
			dp[l][r] = max(dp[l+1][r] + v[l], dp[l][r-1] + v[r]);
		}
		else {
			dp[l][r] = min(dp[l+1][r] - v[l], dp[l][r-1] - v[r]);
		}
		if(l > 0)q.push(MP(l-1,r));
		if(r < n - 1)q.push(MP(l,r+1));
	}
	
	cout << dp[0][n-1] << endl;
	
	return 0;
}
