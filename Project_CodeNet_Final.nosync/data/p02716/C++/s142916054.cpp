#include<bits/stdc++.h>
using namespace std;
//#pragma GCC target ("avx")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define siz(s) (int)s.size()

template<class T> inline bool chmin(T &a, T b) {
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if(a<b){a=b;return true;}
	return false;
}
template<class T> inline int getidx(vector<T> &v, T a) {
	return lower_bound(all(v), a) - v.begin();
}

constexpr int mod=1e9+7;
constexpr int inf=3e18;

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)res=res*x%m;
		y>>=1;x=x*x%m;
	}
	return res;
}
int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int N,A[2000005];
map<int,int>dp[200005][2];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>N;
	rep(i,N)cin>>A[i];
	rep(i,N+1){
		rep(j,2)rep(k,2)dp[i][k][(i+1)/2-j]=-inf;
	}
	dp[0][0][0]=0;
	rep(i,N){
		for(int j=(i+1)/2-1;j<=(i+1)/2;j++){
			if(j<0)continue;
			chmax(dp[i+1][0][j],max(dp[i][0][j],dp[i][1][j]));
			chmax(dp[i+1][1][j+1],dp[i][0][j]+A[i]);
		}
	}
	cout<<max(dp[N][0][N/2],dp[N][1][N/2])<<"\n";
}
