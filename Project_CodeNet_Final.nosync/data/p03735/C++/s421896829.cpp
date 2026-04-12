#include<cstdio>
#include<algorithm>
const int maxn=400010;
int n;
int a[maxn];
int ps[maxn],rk[maxn];
int rv[maxn];
long long ans;
int In() {
	register char c;
	for(;c=getchar(),c!='-'&&(c<'0'||c>'9'););
	register bool f=c=='-';
	register int s=f?0:c-'0';
	for(;c=getchar(),c>='0'&&c<='9';)s=s*10+c-'0';
	return f?-s:s;
}
bool cmp(const int &x,const int &y) {
	return a[x]<a[y];
}
void cmin(register long long &a,register long long b) {
	a>b?a=b:0;
}
int dmin(register int a,register int b) {
	return a<b?a:b;
}
int main() {
	ans=1ll<<60;
	n=In();
	for(register int i=1;i<=n;++i)a[i]=In(),a[i+n]=In();
	if(n==1) return puts("0"),0;
	for(register int i=1;i<=n*2;++i)ps[i]=i;
	std::sort(ps+1,ps+n*2+1,cmp);
	for(register int i=1;i<=n*2;++i)rk[ps[i]]=i;
	for(register int i=1;i<=n*2;++i)if(ps[i]<=n) rv[rv[i]=rk[ps[i]+n]]=i;
	register int lm=2;
	while(rv[lm]!=1&&lm<rv[lm])++lm;
	register int xx=a[ps[rv[n*2]]];
	for(register int i=n*2-1;i>=1;--i) {
		cmin(ans,1ll*(a[ps[n*2]]-a[ps[lm]])*(a[ps[i]]-a[ps[1]]));
		cmin(ans,1ll*(a[ps[n*2]]-a[ps[1]])*(a[ps[i]]-dmin(a[ps[lm]],xx)));
		if(rv[i]==n*2||rv[i]>i) break;
		xx>a[ps[rv[i]]]?xx=a[ps[rv[i]]]:0;
	}
	printf("%lld\n",ans);
	return 0;
}