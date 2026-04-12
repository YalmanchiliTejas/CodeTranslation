#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 1e7;
long long int pw[maxn+1],fac[maxn+1],inv[maxn+1];

long long int C(int n,int k){
	return fac[n]*inv[k]%mod*inv[n-k]%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pw[0]=fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=maxn;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	}
	for(int i=2;i<=maxn;i++)
		inv[i]=inv[i]*inv[i-1]%mod;
	int n;
	cin>>n;
	long long int ans = 1;
	for(int i=1;i<=n;i++)
		ans=ans*3%mod,pw[i]=pw[i-1]*2%mod;
	long long int tot = 0;
	for(int i=0;i<n/2;i++)
		tot += pw[i] * C(n,i)%mod;
	tot*=2;
	ans -= tot;
	cout<<(ans%mod+mod)%mod<<endl;
}
