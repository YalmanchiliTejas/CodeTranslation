#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mo=998244353;
const int N=100001;
const int K=10000;
char s1[10002],s2[10002];
LL fac[100001],inv[100001];
int f[10001][10001];
LL mul(LL x,LL y) {
	if (y==0) return 1;
	LL now=mul(x,y/2);
	now=now*now%mo;
	if (y%2) now=now*x%mo;
	return now;
}
void pre_choose() {
	fac[0]=1;
	for (LL i=1;i<=N;i++) fac[i]=fac[i-1]*i%mo;
	inv[N]=mul(fac[N],mo-2);
	for (LL i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mo;
}
LL C(LL x,LL y) {
	if (y>x||y<0) return 0;
	return fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void pre_dp() {
	f[0][0]=1;
	for (LL i=1;i<=K;i++)
		for (LL j=1;j<=K;j++)
			f[i][j]=((LL)f[i-1][j]*j%mo+f[i-1][j-1])%mo;
}
int main() {
	pre_choose();
	pre_dp();
	scanf("%s",s1);
	scanf("%s",s2);
	int cnt1=0,cnt2=0;
	int len=strlen(s1);
	for (int i=0;i<len;i++) {
		if (s1[i]=='1'&&s2[i]=='1') cnt1++;
		if (s1[i]=='1'&&s2[i]=='0') cnt2++;
	}
	LL ans=0;
	int k=cnt1+cnt2;
	for (int i=cnt2;i<=k;i++) {
		LL now=C(k,i)*f[i][cnt2]%mo*fac[k-i]%mo*fac[k-i]%mo*fac[cnt2]%mo*fac[cnt2]%mo;
		now=now*fac[i-cnt2]%mo*C(cnt1,i-cnt2)%mo;
		ans=(ans+now)%mo;
	}
	printf("%lld\n",ans);
	return 0;
}