#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll Pow(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

ll n;
vl a;
vvl dp,DP;

int main(){
	cin>>n;
	a=vl(n+2);
	dp=DP=vvl(n+2,vl(n+2));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=0;k<n;k++) for(int i=1;i<=n;i++) if(i+k<=n&&a[i-1]<a[i]||a[i+k]>a[i+k+1]){
		ll L=i,R=i+k,m=inf,M=max(a[i-1],a[i+k+1]);
		for(int j=L;j<=R;j++) m=min(m,a[j]);
		if(m<=M) continue;
		vi b,c;
		ll I=L,t=0;
		for(int j=L;j<=R;j++) if(a[j]==m){
			t++;
			if(I!=j){
				b.push_back(I);
				c.push_back(j-1);
			}
			I=j+1;
		}
		if(I!=R+1){
			b.push_back(I);
			c.push_back(R);
		}
		if(t==R-L+1){
			dp[L][R]=Pow(2,m-M-1);
			DP[L][R]=(Pow(2,t)+mod-2)%mod;
			continue;
		}
		ll S=b.size(),res=1,sum=Pow(2,t);
		for(int j=0;j<S;j++){
			int l=b[j],r=c[j];
			(res*=2*dp[l][r])%=mod;
			(sum*=4*dp[l][r]+DP[l][r])%=mod;
		}
		(sum+=2*mod-2*res)%=mod;
		(res*=Pow(2,m-M-1))%=mod;
		dp[L][R]=res,DP[L][R]=sum;
	}
	cout<<(2*dp[1][n]+DP[1][n])%mod<<endl;
}