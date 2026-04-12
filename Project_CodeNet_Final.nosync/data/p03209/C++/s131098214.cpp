#include <bits/stdc++.h>
typedef long long ll;
#define  rep(i,a,b)for(long long i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
const ll INF=100000000LL;
const ll r197=1000000007;
typedef pair<ll,ll>P;
typedef pair<P,P>Pa;
bool Inframe(int a,int b,int c,int d,int h,int w){
	if(a+b>=0&&a+b<h&&c+d>=0&&c+d<w)return true;
	return false;
}
int h,w;
int l[1001][1001];
ll dp1[50]={3};
ll dp2[50]={5};
int g=1;
bool b[1001][1001]={};
int d[1001][1001]={};
ll calc(ll y,int m){
	if(y==0)return 0;
	if(m==0){
		return min(y-1,(ll)3);
	}
	if(y==dp2[m]/2){
		return dp1[m-1];
	}
	if(y<dp2[m]/2){
		return calc(y-1,m-1);
	}
	if(y>dp2[m]/2){
		return dp1[m-1]+1+calc(y-dp2[m]/2-1,m-1);
	}
	return 0;
}
int main() {
	int n;
	ll x;
	cin>>n>>x;
	rep(i,1,50){
		dp1[i]=dp1[i-1]*2+1;
	}
	rep(i,1,50){
		dp2[i]=dp2[i-1]*2+3;
	}
	cout<<calc(x,n-1)<<endl;
	return 0;

}
