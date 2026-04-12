#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int P=1e9+7;
const int N=2e5+10;
int n,m,k;
LL fac[N],inv[N];

LL power(LL x,LL p) {
	LL ret=1;
	for (;p;p>>=1) {
		if (p&1) ret=ret*x%P;
		x=x*x%P;
	}
	return ret;
}

void prework() {
	fac[0]=1; inv[0]=power(fac[0],P-2);
	for (int i=1;i<=200000;i++) {
		fac[i]=fac[i-1]*i%P;
		inv[i]=power(fac[i],P-2);
	}
}

LL C(LL n,LL m) {
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int main()
{
	prework();
	cin>>n>>m>>k;
	LL ans=C(n*m,k)%P*C(k,2)%P*(n+m)%P*power(3,P-2)%P;
	cout<<ans<<endl;
	return 0;
}