#include<bits/stdc++.h>
using namespace std;

const int N=100100,mod=998244353;
typedef long long ll;
int ksm(ll a,int b,int c=1){
	for(;b;b/=2,a=a*a%mod)
		if(b&1)c=c*a%mod;
	return c;
}
char S[N],T[N];
int n,f[N],jc[N],jc2[N],ans;

void init(){
	jc[0]=1;
	for(int i=1;i<N;++i)jc[i]=(ll)jc[i-1]*i%mod;
	jc2[N-1]=ksm(jc[N-1],mod-2);
	for(int i=N-1;i;--i)jc2[i-1]=(ll)jc2[i]*i%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>S>>T;n=strlen(S);init();
	int p=0,q=0;
	for(int i=0;i<n;++i)
		if(S[i]=='1'){if(T[i]=='0')++p;else ++q;}
	f[0]=1;
	for(int i=1;i<=p;++i)
		for(int j=1;j<=q;++j)
			f[j]=(f[j]+(ll)i*f[j-1])%mod;
	for(int i=0;i<=q;++i)ans=(ans+(ll)f[i]*jc2[p+i])%mod;
	ans=(ll)ans*jc[p]%mod*jc[p]%mod*jc[q]%mod*jc[p+q]%mod;
	cout<<ans<<'\n';
	return 0;
}
