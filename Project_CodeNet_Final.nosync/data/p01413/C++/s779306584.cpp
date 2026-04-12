#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m, w, t, v[10], p[10];
int x[10], y[10], l[10], r[10][10], q[10][10];
int d[1 << 10][10];
ll dp2[10001];
string s[10];
map<string, int> id;

int main(){
	cin >> n >> m >> w >> t;
	rep(i, m){
		cin >> s[i] >> v[i] >> p[i];
		id[s[i]] = i;
	}
	rep(i, n){
		cin >> l[i] >> x[i] >> y[i];
		rep(j, l[i]){
			string a;
			cin >> a >> q[i][j];
			r[i][j] = id[a];
		}
	}
	rep(i, 1 << n + 1) rep(j, n + 1) d[i][j] = inf;
	d[0][n] = 0;
	rep(i, 1 << n + 1) rep(j, n + 1) if(d[i][j] < inf) rep(k, n + 1) if(!(i & 1 << k)){
		d[i | 1 << k][k] = min(d[i | 1 << k][k], d[i][j] + abs(x[j] - x[k]) + abs(y[j] - y[k]));
	}
	vector<pi> it;
	rep(i, 1 << n){
		static ll dp[10001];
		rep(j, w + 1) dp[j] = 0;
		rep(j, n) if(i & 1 << j) rep(k, l[j]) rep(h, w) if(h + v[r[j][k]] <= w){
			dp[h + v[r[j][k]]] = max(dp[h + v[r[j][k]]], dp[h] - q[j][k] + p[r[j][k]]);
		}
		it.pb(mp(d[i | 1 << n][n], dp[w]));
	}
	rep(i, t) rep(j, it.size()) if(i + it[j].first <= t)
	dp2[i + it[j].first] = max(dp2[i + it[j].first], dp2[i] + it[j].second);
	
	cout << dp2[t] << endl;
	return 0;
}