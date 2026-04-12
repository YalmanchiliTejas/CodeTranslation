#include<bits/stdc++.h>
#define mxn 1000010
#define db double
#define LL long long
#define ldb long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pul pair<ull,LL> 
#define pii pair<int,int> 
#define mp make_pair
#define fr first
#define sc second
#define x1 faqx1
#define y1 faqy1
#define x2 faqx2
#define y2 faqy2
using namespace std;
const int mod=998244353;
template<typename T> void chkmin(T &x,T y) {if(y<x) x=y;}
template<typename T> void chkmax(T &x,T y) {if(y>x) x=y;}
template<typename T> void upd(T &x,T y) {if((x+=y)>=mod) x-=mod;}
int n,K,sl,fh,ans,a[3010],f[3010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main()
{
	n=rd();K=rd();
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1;i<=n;++i)
		if(a[i]<=K)
		{
			ans=(ans+i*(n-i+1)*(a[i]==K)+1ll*f[K-a[i]]*(n-i+1))%mod;
			for(int j=K;j>=a[i];--j) upd(f[j],f[j-a[i]]);
			upd(f[a[i]],i);
		}
	printf("%d\n",ans);
	return 0;
}