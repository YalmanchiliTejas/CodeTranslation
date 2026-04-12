#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <queue>
#define inp(X) cin >> X
#define out(X) cout << X << endl
#define out16(X) cout << setprecision(16) << X << endl
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vd = std::vector<double>;
using vvd = std::vector<std::vector<double>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using namespace std;
#define MOD 1000000007
#define INF 1000000001
#define LL_INF 1001001001001001001

ll gcd(ll x, ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

bool bfs(vector<vector<int>> g, vector<int> &dist, int sv){
	queue<int> q;
	q.push(sv);
	dist[sv]=0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto v : g[now]){
			if(dist[v]!=-1) continue;
			dist[v] = dist[now]+1;
			q.push(v);
		}
	}
}

int main(void) {
	string n; cin >> n;	
	int d; cin >> d;
	vi v; rep(i,n.size()) v.push_back(n[i]-'0');
	int l=v.size();
	vector<vector<vector<ll>>> dp(l+1,vvll(2,vll(d,0)));
	dp[0][0][0]=1;
	rep(i,l)rep(j,2)rep(k,d){
		for(int x=0; x<=(j?9:v[i]); x++){
			dp[i+1][j||x!=v[i]][(k+x)%d] += dp[i][j][k];
			dp[i+1][j||x!=v[i]][(k+x)%d] %= MOD;
		}
	}
	out( ((dp[l][0][0]+dp[l][1][0])%MOD -1ll + MOD )%MOD);
}


