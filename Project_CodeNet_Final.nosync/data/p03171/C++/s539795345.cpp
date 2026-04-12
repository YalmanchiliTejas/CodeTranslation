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
using vivi = std::vector<std::vector<int>>;
using vd = std::vector<double>;
using vll = std::vector<ll>;
using vllvll = std::vector<std::vector<ll>>;


using namespace std;

#define MOD 1000000007
#define INF 1000000001

ll gcd(ll x, ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

bool bfs(vector<vector<int>> g, vector<int> &dist, int sv)
{
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
	ll n; cin >> n;
	vll a(n); rep(i,n) cin >> a[i];
	vllvll dp(n+1,vll(n+1,0)); //dp[i][j]:[i,j)区間でのX-Y
	//dp[i][i]=0
	rep2(len,1,n+1){
		rep(i,n-len+1){
			ll j = i+len;
			if((n-len)/*とった数*/ %2)dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
			else dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
		}
	}
	out(dp[0][n]);
}


