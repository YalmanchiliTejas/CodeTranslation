#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
int N;
V<ll> a;
VV<ll> dp;
int main(){
	cin>>N;
	a.resize(N);
	rep(i,N) cin>>a[i];
	dp = VV<ll>(N+1,V<ll>(N+1));
	rep1(len,N){
		rep(l,N-len+1){
			int r = l+len;
			if((N-len)%2 == 0){
				dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
			}else{
				dp[l][r] = min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
			}
		}
	}
	cout<<dp[0][N]<<endl;
}