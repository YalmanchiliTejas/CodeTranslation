#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

const int N=200;

int h,w;
int a[N][N];
int dp[N][N][2*N];

int dx1[]={1,0,1,0},dy1[]={0,1,0,1};
int dx2[]={1,1,0,0},dy2[]={0,0,1,1};

int dfs(int X1,int Y1,int X2,int Y2) {
	if(dp[X1][X2][X1+Y1]!=-1) return dp[X1][X2][X1+Y1];
	int res=0;
	res+=a[Y1][X1];
	if(X1!=X2||Y1!=Y2) res+=a[Y2][X2];
	int ma=0;
	REP(i,4) {
		int nx1=X1+dx1[i],ny1=Y1+dy1[i];
		int nx2=X2+dx2[i],ny2=Y2+dy2[i];
		if(nx1<0||nx1>=w||ny1<0||ny1>=h||nx2<0||nx2>=w||ny2<0||ny2>=h) continue;
		ma=max(ma,dfs(nx1,ny1,nx2,ny2));
	}
	//cout<<'('<<X1<<','<<Y1<<','<<X2<<','<<Y2<<')'<<' '<<res<<' '<<ma<<endl;
	return dp[X1][X2][X1+Y1]=res+ma;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>h>>w;
	REP(i,h) REP(j,w) cin>>a[i][j];
	REP(i,N) REP(j,N) REP(k,2*N) dp[i][j][k]=-1;

	cout<<dfs(0,0,0,0)<<endl;

	return 0;
}
