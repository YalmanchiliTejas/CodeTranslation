#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll ppow(ll a,ll b){
	a%=MOD;
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
ll t=MOD/2+1;
ll calc(ll h){
	return (h-1)*h%MOD*t%MOD;
}
class Fact{
	vector<ll>fact;
	vector<ll>inv;
public:
	Fact(){}
	Fact(int n){
		n=n*2+10;
		fact=inv=vector<ll>(n);
		fact[0]=inv[0]=1;
		for(int i=1;i<n;i++){
			fact[i]=(fact[i-1]*i)%MOD;
			inv[i]=ppow(fact[i],MOD-2);
		}
	}
	ll get(int n){
		return fact[n];
	}
	ll nPr(int n,int r){
		return fact[n]*inv[n-r]%MOD;
	}
	ll nCr(int n,int r){
		return nPr(n,r)*inv[r]%MOD;
	}
	ll nrP(int n,int r){
		return nPr(n+r,n);
	}
	ll nrC(int n,int r){
		return nCr(n+r,n);
	}
};
int main(){
	int n,m,K;cin>>n>>m>>K;
	ll sum=0;
	Fact fac(n*m);
	rep(i,n)rep(j,m){
		(sum+=(calc(i+1)+calc(n-i))%MOD*m)%=MOD;
		(sum+=(calc(j+1)+calc(m-j))%MOD*n)%=MOD;
	}
	(sum*=t)%=MOD;
	cout<<sum*fac.nCr(n*m-2,K-2)%MOD<<endl;
}