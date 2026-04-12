#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll fact[1000000], fact_inv[1000000];

// 繰り返し二乗法
ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

ll comb(ll n, ll r){
	return (fact[n]*fact_inv[r])%mod*fact_inv[n-r]%mod;
}
int main(){
  ll N,M,K;cin>>N>>M>>K;
  ll A,B;
  ll i,j,k,l;
  //x軸とy軸で別々に考える
  //残りの点の選び方(N*M-2)C(K-2)
  fact[0]=1;
        // 階乗の計算
	rep(i,N*M) fact[i+1]=fact[i]*(i+1)%mod;
	fact_inv[M*N]=power(fact[M*N], mod-2);
        // 逆元の計算
	for(i=N*M-1;i>=0;i--) fact_inv[i]=fact_inv[i+1]*(i+1)%mod;
  //2点の距離dにする選び方は(N-d)*M**2
  ll Res=comb(N*M-2,K-2);
  //cout<<Res<<endl;
  ll x=0,y=0;
  repn(i,N-1){
    x+=i*(N-i)*M*M;
    if(x>mod) x%=mod;
  }
  repn(i,M-1){
    y+=i*(M-i)*N*N;
    if(y>mod) y%=mod;
  }
  ll ans=x+y;
  //cout<<x<<" "<<y<<endl;
  ans*=Res;
  ans%=mod;
  cout<<ans<<endl;
}
