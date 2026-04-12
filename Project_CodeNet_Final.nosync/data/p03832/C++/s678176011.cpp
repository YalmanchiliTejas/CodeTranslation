#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<pii,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?2e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
//nCr mod m
#define MOD 1000000007
#define M 1000000
vector<ll> fact;
bool h=false;
void init(){
	h=true;
	fact=vector<ll>(M);
	fact[0]=fact[1]=1;
	loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// a^b mod MOD
ll powmod(ll a,ll b,ll m){
	ll out=1;
	ll p=a%m;
	while(b){
		if(b&1)out=out*p%m;
		p=p*p%m;
		b>>=1;
	}
	return out;
}
//nCr
ll nCr(ll n,ll r,ll m){
	if(!h)init();
	if(n<0||r<0||n<r)return 1;//??????
	ll out=fact[n]*powmod(fact[r]*fact[n-r]%m,m-2,m)%m;
	return out;
}
ll nCr(ll n,ll r){return nCr(n,r,MOD);}
int main(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	vi dp(n+1);
	dp[0]=1;
	loop(i,a,b+1){
		vi w(n+1);
		rep(j,n+1)w[j]=nCr(j,i);
		for(int k=n;k>=0;k--){
			ll co=1;
			rep(j,c-1)if(n-k+i*(j+1)<n+1)(co*=w[n-k+i*(j+1)])%=MOD;
			loop(j,c,d+1){
				if(k-i*j<0)break;
				(co*=w[n-k+i*j])%=MOD;
				(dp[k]+=co*dp[k-i*j]%MOD*powmod(fact[j],MOD-2,MOD)%MOD)%=MOD;
			}
		}
	}
	cout<<dp[n]<<endl;
}








