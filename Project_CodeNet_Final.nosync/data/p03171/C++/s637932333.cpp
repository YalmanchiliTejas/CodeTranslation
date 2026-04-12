#include <iostream>
#include <algorithm>
typedef long long ll;
#define  rep(i,a,b)for(long long i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
const ll INF=1000000000000LL;
const ll r197=1000000007;
typedef pair<ll,ll>P;
typedef pair<P,P>Pa;
bool Inframe(int a,int b,int c,int d,int h,int w){
	if(a+b>=0&&a+b<h&&c+d>=0&&c+d<w)return true;
	return false;
}
ll dp[3003][3003]={};
int n;
ll a[3003];
ll reg(int m,int s){
	if(dp[m][s]!=INF)return dp[m][s];
	if(s==n)return 0;
	ll res;
	if(s%2==0){
		res=max(a[m]+reg(m+1,s+1),a[m+n-s-1]+reg(m,s+1));
	}else{
		res=min(-a[m]+reg(m+1,s+1),-a[m+n-s-1]+reg(m,s+1));
	}
	return dp[m][s]=res;
}

int main() {
	cin>>n;
	rep(i,0,n+1){
		rep(j,0,n+1)dp[i][j]=INF;
	}
	rep(i,0,n)cin>>a[i];
	cout<<reg(0,0)<<endl;
	return 0;
}
