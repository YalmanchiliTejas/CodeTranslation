#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long

using namespace std;

const int N=1e7+10,mod=998244353;
int n,fac[N],inv[N],pw[N],ans;

int C(int n,int m){
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void upd(int &x,int y){x+=y; x-=x>=mod?mod:0;}

int ksm(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) s=(ll)s*x%mod;
	return s;
}

void init(int n){
	fac[0]=1;
	rep (i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for (int i=n;i;i--) inv[i-1]=(ll)inv[i]*i%mod;
	pw[0]=1;
	rep (i,1,n) pw[i]=(ll)pw[i-1]*2%mod;
}

int main(){
	scanf("%d",&n); init(n);
	rep (i,n/2+1,n) upd(ans,(ll)C(n,i)*pw[n-i]%mod);
	printf("%lld\n",(ksm(3,n)+mod-ans*2ll%mod)%mod);
	return 0;
}