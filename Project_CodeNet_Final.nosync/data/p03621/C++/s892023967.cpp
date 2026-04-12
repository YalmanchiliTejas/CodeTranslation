#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int MAXN = 10003;
const int mo = 998244353;
const int g = 3;

LL js[MAXN],inv[MAXN];
int n,t,m;
int a[MAXN],b[MAXN];
int N,L;
LL A[33400],mi[33400],bitr[33400],ans[33400],ny;

LL calc(int n,int m){
	return js[n]*inv[m]%mo*inv[n-m]%mo;
}

LL quickmi(LL x,LL tim){
	LL ans=1;
	x=x%mo;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ans=ans*x%mo;
	return ans;
}

void prepare(){
	fo(i,0,N-1){
		bitr[i]=0;
		fo(j,0,L-1)
		if ((i&(1<<j))>0)bitr[i]|=1<<(L-1-j);
	}
	LL G=quickmi(g,(mo-1)/N);
	ny=quickmi(N,mo-2);
	mi[0]=1;
	fo(i,1,N)mi[i]=mi[i-1]*G%mo;
}

LL add(LL x,LL y){
	return x+y>=mo?x+y-mo:x+y;
}

LL dec(LL x,LL y){
	return x>=y?x-y:x+mo-y;
}

void DFT(LL *a){
	fo(i,0,N-1)
	if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			LL w=mi[N/now*i];
			for(int j=i;j<N;j+=now){
				LL l=a[j],r=w*a[j+half]%mo;
				a[j]=add(l,r);
				a[j+half]=dec(l,r);
			}
		}
	}
}

void IDFT(LL *a){
	fo(i,0,N-1)
	if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			LL w=mi[N-N/now*i];
			for(int j=i;j<N;j+=now){
				LL l=a[j],r=w*a[j+half]%mo;
				a[j]=add(l,r);
				a[j+half]=dec(l,r);
			}
		}
	}
	fo(i,0,N-1)a[i]=a[i]*ny%mo;
}

void twice(LL *a){
	DFT(a);
	fo(i,0,N-1)a[i]=a[i]*a[i]%mo;
	IDFT(a);
	fo(i,t+1,N-1)a[i]=0;
}

LL C[33400];

void ntt(LL *a,LL *b){
	fo(i,0,N-1)C[i]=b[i];
	DFT(a),DFT(b);
	fo(i,0,N-1)a[i]=a[i]*b[i]%mo;
	IDFT(a);
	fo(i,0,N-1)b[i]=C[i];
	fo(i,t+1,N-1)a[i]=0;
}

int main(){
	char s[MAXN];
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n)a[i]=s[i]-'0';
	scanf("%s",s+1);
	fo(i,1,n)b[i]=s[i]-'0';
	fo(i,1,n){
		if (a[i]&&b[i])t++;
		m+=(a[i]+b[i])&1;
	}
	js[0]=inv[0]=inv[1]=1;
	fo(i,1,n)js[i]=js[i-1]*i%mo;
	fo(i,2,n)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,1,n)inv[i]=inv[i]*inv[i-1]%mo;
	m/=2;
	ans[0]=js[t];
	N=1,L=0;
	while(N<=2*t)N<<=1,L++;
	prepare();
	fo(i,0,t)A[i]=inv[i+1];
	for(int tim=m;tim;tim/=2,twice(A))
		if (tim&1)ntt(ans,A);
	fo(i,0,t)ans[i]=ans[i]*inv[t-i]%mo*js[i+m]%mo;
	LL val=0;
	fo(i,0,t)val=(val+ans[i]*js[t-i]%mo*js[t-i]%mo*calc(m+t,t-i)%mo)%mo;
	val=val*js[m]%mo;
	printf("%lld\n",val);
	return 0;
}