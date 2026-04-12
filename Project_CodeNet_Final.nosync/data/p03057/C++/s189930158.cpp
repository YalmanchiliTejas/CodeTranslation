#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m;
char ss[200005];
int f[200005],qz[200005];
int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",&ss[1]);
	bool mk = 0;
	int mx = 0;
	for(int i=1;i<=m;i++) {
		if(ss[i]!=ss[1]) { mk = 1; mx = i-1; break; }
	}
	if(!mk) {
		int ans = 1;
		f[0] = qz[0] = 1;
		for(int i=0;i<=n;i++) {
			if(i>=2) f[i] = qz[i-2];
			if(i!=0)qz[i] = (qz[i-1]+f[i])%mod;
			if(n-i>=2) ans = (ans+1ll*f[i]*(n-i)%mod)%mod;
		}
		printf("%d",ans);
		return 0;
	}
	if(n&1) {
		puts("0"); return 0;
	}
	int lx = 0;
	for(int i=1;i<=m;i++) {
		if(ss[i]==ss[1]) lx++;
		else {
			if(lx&1) mx = min(mx,lx);
			lx = 0;
		}
	}
	mx = mx/2+1;
	n/=2;
	f[0] = qz[0] = 1;
	int ans = 0;
	for(int i=0;i<=n;i++) {
		if(i) {
			f[i] = (qz[i-1] - (i-mx-1>=0?qz[i-mx-1]:0) )%mod;
			qz[i] = (qz[i-1]+f[i])%mod;
		}
		if(n-i<=mx) ans = (ans + 1ll * f[i]*2%mod*(n-i)%mod )%mod;
	}
	printf("%d",(ans%mod+mod)%mod );
}