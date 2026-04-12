#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;

int a[200000], dp[200000], s[200000];
vector<int> vs;
signed main(){
	int n, g = 1;
	scanf("%lld", &n);
	rep(i,n)scanf("%lld", &a[i]);
	int mx = *max_element(a, a+n);
	repi(i,2,40000){
		while(mx%i == 0){mx /= i;vs.pb(i);}
		if(mx == 1)break;
	}
	dp[1] = 1;
	rep(j,vs.size()){
		drep(i,40000,1){
			if(i*vs[j] <= 40000 and dp[i])dp[i*vs[j]] = 1;
		}
	}
	drep(i,40000,1){
		if(dp[i] == 1)s[i] = i;
		else s[i] = s[i+1];
	}
	
	int ans = 0;
	rep(i,n)ans += s[a[i]]-a[i];
	printf("%lld\n", ans);
	//rep(i,10)printf("%lld ", s[i]);
	return 0;
}





