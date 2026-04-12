#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

ll a[3010];

ll dp[3010][3010][2];
bool done[3010][3010][2];

ll func(int l,int r,int p) {
	if (done[l][r][p]) return dp[l][r][p];
	if (l==r) {
		done[l][r][p]=true;
		if (p) {
			return dp[l][r][1]=a[l];
		} else {
			return dp[l][r][0]=-a[l];
		}
	}
	if (p) {
		dp[l][r][p]=max(func(l+1,r,0)+a[l],func(l,r-1,0)+a[r]);
		// dp[l][r][p]=max(dp[l+1][r][0]+a[l],dp[l][r-1][0]+a[r]);
	} else {
		dp[l][r][p]=min(func(l+1,r,1)-a[l],func(l,r-1,1)-a[r]);
		// dp[l][r][p]=min(dp[l+1][r][1]-a[l],dp[l][r-1][1]-a[r]);
	}
	done[l][r][p]=true;
	return dp[l][r][p];
}

int main(int argc, char const *argv[])
{
	
	int n;cin>>n;

	rep(i,n) cin>>a[i];

	ll ans = func(0,n-1,1);

	cout<<ans<<endl;

	return 0;
}