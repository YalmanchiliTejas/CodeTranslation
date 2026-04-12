#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int(i) = (n)-1; (i) >= 0; (i)--)
 
int mod=1e9+7;

struct modCalc{
	int mod;
	int n;
	vector<int> fact,invfact;

	modCalc(){};
	modCalc(int _mod,int _n){
		mod=_mod,n=_n;
		fact.resize(n+1,1);
		invfact.resize(n+1,1);
		for(int i=0;i<n;i++)fact[i+1]=fact[i]*(i+1)%mod;
		invfact[n]=modinv(fact[n]);
		for(int i=n;i>1;i--)invfact[i-1]=invfact[i]*i%mod;
	};

	int modpow(int x,int n){
		int ret=1;
		while(n>0){
			if(n&1)(ret*=x)%=mod;
			(x*=x)%=mod;
			n>>=1;
		}
		return ret;
	}

	int modinv(int x){
		return modpow(x,mod-2);
	}

	int nCm(int x,int y){
		if(y==0)return 1;
		else return fact[x]*invfact[y]%mod*invfact[x-y]%mod;
	}
	int nPm(int x,int y=-1){
		if(y==-1)y=x;
		return fact[x]*invfact[x-y]%mod;
	}
};



signed main() {
	int n,m,k;cin>>n>>m>>k;

	modCalc md(mod,n*m);
	int combNum=md.nCm(n*m-2,k-2);
	int ret=0;
	for(int i=1;i<n;i++)(ret+=i*(n-i)*m*m)%=mod;
	for(int i=1;i<m;i++)(ret+=i*(m-i)*n*n)%=mod;
	cout<<ret*combNum%mod<<endl;

}