#include<bits/stdc++.h>
#define mo 998244353
#define N 32800
using namespace std;
int a[N],b[N],R[N];
char s1[N],s2[N];
int n[N],ans[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
void FFT(int *a,int n,int f){
	for (int i=0;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*w*a[j+d]%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
int m,e;
void solve(int times,int c){
	for (;times;){
		FFT(a,c,1);
		if (times&1){
			FFT(b,c,1);
			for (int i=0;i<c;i++)
				b[i]=1ll*b[i]*a[i]%mo;
			FFT(b,c,-1);
			for (int i=m+1;i<c;i++) b[i]=0;
		}
		if (times/=2){
			for (int i=0;i<c;i++)
				a[i]=1ll*a[i]*a[i]%mo;
			FFT(a,c,-1);
			for (int i=m+1;i<c;i++) a[i]=0;
		}
	}
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	int n=strlen(s1+1);
	m=0,e=0;
	for (int i=1;i<=n;i++)
		if (s1[i]^s2[i]) e++;
		else if (s1[i]-'0') m++;
	e/=2;
	a[0]=b[0]=1;
	for (int i=1;i<=m;i++)
		a[i]=1ll*a[i-1]*power(i+1,mo-2)%mo;
	int c=1,L=0;
	for (;c<=2*m;c<<=1,L++);
	for (int i=1;i<c;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	solve(e,c);
	int ans=0;
	for (int i=0;i<=m;i++)
		ans=(ans+b[i])%mo;
	for (int i=1;i<=m;i++)
		ans=1ll*ans*i%mo;
	for (int i=1;i<=e;i++)
		ans=1ll*ans*i%mo;
	for (int i=1;i<=m+e;i++)
		ans=1ll*ans*i%mo;
	printf("%d\n",ans);
} 