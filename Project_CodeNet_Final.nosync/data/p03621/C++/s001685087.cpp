#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#define MAXN 66010
#define LL long long 
using namespace std;

const LL P=998244353;

LL getPow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1) res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}

int n,n1,n2,sizew;
LL fac[MAXN],invfac[MAXN];
LL *a[MAXN],b[MAXN];

void init(){
	static char s1[MAXN],s2[MAXN];
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int len=strlen(s1+1);
	for(int i=1;i<=len;i++)
		if(s1[i]=='1' && s2[i]=='1') n1++;
		else if(s1[i]=='1' || s2[i]=='1') n2++;
	n2/=2;
	n=n1+n2;
	fac[0]=1;
	for(int i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%P;
	invfac[MAXN-1]=getPow(fac[MAXN-1],P-2);
	for(int i=MAXN-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%P;
}

void FFT(LL *a,int len,int flag){
	static int rev[MAXN];
	for(int i=1;i<len;i++){
		rev[i]=rev[i>>1]>>1|((i&1)?(len>>1):0);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int l=2;l<=len;l<<=1){
		LL w=getPow(3,(P-1)/l);
		int l2=l/2;
		for(int i=0;i<len;i+=l){
			LL temp=1;
			for(int j=0;j<l2;j++){
				LL t1=a[i+j],t2=a[i+j+l2]*temp;
				a[i+j]=(t1+t2)%P;
				a[i+j+l2]=(t1-t2)%P;
				temp=temp*w%P;
			}
		}
	}
	if(flag==-1){
		LL invn=getPow(len,P-2);
		for(int i=1;i<len;i++) if(i<len-i) swap(a[i],a[len-i]);
		for(int i=0;i<len;i++) a[i]=(a[i]*invn%P+P)%P;
	}
}

void mul(LL *a,LL *b,int len){
	static LL t1[MAXN],t2[MAXN];
	for(int i=0;i<len;i++) t1[i]=a[i],t2[i]=b[i],t1[i+len]=t2[i+len]=0;
	FFT(t1,len<<1,1); FFT(t2,len<<1,1);
	for(int i=0;i<(len<<1);i++) t1[i]=t1[i]*t2[i]%P;
	FFT(t1,len<<1,-1);
	for(int i=0;i<(len<<1);i++) a[i]=t1[i];
}

void getInv(LL *b,LL *a,int len){
	if(len==1){
		b[0]=1;
		return;
	}
	static LL t1[MAXN],t2[MAXN];
	getInv(t1,a,len>>1);
	for(int i=(len>>1);i<len;i++) t1[i]=0;
	for(int i=0;i<len;i++) t2[i]=a[i];
	FFT(t1,len<<1,1); FFT(t2,len<<1,1);
	for(int i=0;i<(len<<1);i++) t1[i]=(2*t1[i]-t2[i]*t1[i]%P*t1[i]%P+P)%P;
	FFT(t1,len<<1,-1);
	for(int i=0;i<len;i++) b[i]=t1[i];
}

LL getC(int x,int y){
	return fac[x]*invfac[y]%P*invfac[x-y]%P;
}

LL gao(){
	for(sizew=1;sizew<=n1 || sizew<=n2;sizew<<=1);
	static LL space[MAXN];
	for(int i=1;i<=sizew;i++){
		a[i]=space+(i-1)*2;
		a[i][0]=1;
		if(i<=n2) a[i][1]=-i;
	}
	for(int l=2;l<=sizew;l<<=1)
		for(int i=1;i<=sizew;i+=l)
			mul(a[i],a[i+l/2],l);
	getInv(b,a[1],sizew);
	assert(b[0]==1);
	LL ans=0;
	for(int i=0;i<=n1;i++){
		LL temp=getC(n1,i)*b[i]%P*fac[i]%P*fac[n2]%P*fac[n2]%P*fac[n1-i]%P*fac[n1-i]%P*getC(n1+n2,n1-i)%P;
		ans=(ans+temp)%P;
	}
	return ans;
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	init();
	printf("%lld\n",gao());
}