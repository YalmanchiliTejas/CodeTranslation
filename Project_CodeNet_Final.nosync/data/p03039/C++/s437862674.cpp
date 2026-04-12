#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 2e5 +511;
const LL mod=1e9+7;
LL fac[N],inv[N];
int n,m,k;
void P(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=2e5;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=2e5;i++)inv[i]=powmod(fac[i],mod-2,mod);
}
LL get(int a,int b){
	if(b==0)return 1;
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	P();
	cin>>n>>m>>k;
	LL ans=0;
	for(LL i=1;i<m;i++)ans=(ans+(m-i)*i%mod*n%mod*n%mod)%mod;
	for(LL i=1;i<n;i++)ans=(ans+(n-i)*i%mod*m%mod*m%mod)%mod;
	ans=ans*get(n*m-2,k-2)%mod;
	cout<<ans<<endl;
	return 0;
}