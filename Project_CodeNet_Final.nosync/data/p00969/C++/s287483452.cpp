#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int mp[5005][5005];
int dp[5005][5005];

int main(){

	int n;cin >> n;
	vector<ll> v(n);

	REP(i,n)cin >> v[i];
	sort(ALL(v));

	REP(i,5005)REP(j,5005){
		mp[i][j] = -1;
		dp[i][j] = 2;
	}

	REP(i,n){
		int k = i;
		for(ll j = i+1;j < n;j++){
			while(k < n && 2 * v[j] - v[i] > v[k])k++;
			if(k < n && 2 * v[j] - v[i] == v[k])mp[i][j] = k;
		}
	}

	REP(i,n){
		for(ll j = i+1;j < n;j++){
			if(mp[i][j] != -1){
				ll k = mp[i][j];
				dp[j][k] = max(dp[j][k], dp[i][j] + 1);
			}
		}
	}

	int ans = 0;
	REP(i,n){
		REP(j,n){
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}

