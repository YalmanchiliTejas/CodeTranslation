#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int H,W,v[200][200];
ll dp[201][200][200];
int main(){
	cin>>H>>W;
	rep(i,H) rep(j,W) cin>>v[i][j];
	if(W==1){
		ll ans=0;
		rep(i,H) ans+=v[i][0];
		cout<<ans<<endl;
		return 0;
	}
	rep(i,H+1) rep(j,W) rep(k,W) dp[i][j][k]=-1;
	dp[0][0][0]=v[0][0];
	rep(i,H){
		rep(a,W) for(int b=a;b<W;b++) if(dp[i][a][b]){
			if(a+1<b) chmax(dp[i][a+1][b],dp[i][a][b]+v[i][a+1]);
		}
		rep(a,W) for(int b=a;b<W-1;b++) if(dp[i][a][b]){
			chmax(dp[i][a][b+1],dp[i][a][b]+v[i][b+1]);
		}
		if(i==H-1){
			ll ans=0;
			rep(a,W) rep(b,W) chmax(ans,dp[i][a][b]);
			cout<<ans<<endl;
			return 0;
		}
		rep(a,W) for(int b=a+1;b<W;b++) if(dp[i][a][b]){
			dp[i+1][a][b]=dp[i][a][b]+v[i+1][a]+v[i+1][b];
		}
	}
}
