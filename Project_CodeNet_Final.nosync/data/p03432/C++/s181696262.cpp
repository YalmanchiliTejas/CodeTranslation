#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#define ll long long
using namespace std;
int read(){
	int w=0;
	bool s=0;
	char c=getchar();
	while(!isdigit(c)){
		s=(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		w=w*10+c-'0';
		c=getchar();
	}
	return s?-w:w;
}
const int N=20005,Mod=998244353,g=3,ig=332748118;
int n,m,len,l;
int r[N];
int add(int x,int y){
	if(x+y>Mod){
		return x+y-Mod;
	}
	return x+y;
}
int sub(int x,int y){
	y=Mod-y;
	if(x+y>Mod){
		return x+y-Mod;
	}
	return x+y;
}
int mul(int x,int y){
	return (ll)x*(ll)y%Mod;
}	
int power(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res=mul(res,a);
		}
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
int pinv(int x){
	return power(x,Mod-2);
}
void NTT(int* a){
	for(int i=0;i<len;i++){
		if(i<r[i]){
			swap(a[i],a[r[i]]);
		}
	}
	for(int k=1;k<len;k<<=1){
		int w=power(g,(Mod-1)/(k<<1));
		for(int i=0;i<len;i+=(k<<1)){
			int wn=1;
			for(int j=0;j<k;j++){
				int x=a[i+j],y=mul(wn,a[i+j+k]);
				a[i+j]=add(x,y);
				a[i+j+k]=sub(x,y);
				wn=mul(wn,w);
			}
		}
	}
}
void INTT(int* a){
	for(int i=0;i<len;i++){
		if(i<r[i]){
			swap(a[i],a[r[i]]);
		}
	}
	for(int k=1;k<len;k<<=1){
		int w=power(ig,(Mod-1)/(k<<1));
		for(int i=0;i<len;i+=(k<<1)){
			int wn=1;
			for(int j=0;j<k;j++){
				int x=a[i+j],y=mul(wn,a[i+j+k]);
				a[i+j]=add(x,y);
				a[i+j+k]=sub(x,y);
				wn=mul(wn,w);
			}
		}
	}
	int dv=pinv(len);
	for(int i=0;i<len;i++){
		a[i]=mul(a[i],dv);
	}
}
int fac[N],inv[N],inv_fac[N];
int C(int m,int n){
	if(m>n){
		return 0;
	}
	return mul(fac[n],mul(inv_fac[m],inv_fac[n-m]));
}
int F[N],G[N],P[N],Q[N];
int ans;
int main(){
	n=read(),m=read();
	fac[0]=fac[1]=1;
	inv[0]=inv[1]=1;
	inv_fac[0]=inv_fac[1]=1;
	for(int i=2;i<N;i++){
		inv[i]=mul(sub(Mod,Mod/i),inv[Mod%i]);
		fac[i]=mul(fac[i-1],i);
		inv_fac[i]=mul(inv_fac[i-1],inv[i]);
	}
	len=1,l=0;
	while(len<=n+n){
		len<<=1;
		l++;
	}
	for(int i=0;i<len;i++){
		r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	}
	G[0]=P[0]=1;
	for(int i=1;i<=n;i++){
		Q[i]=inv_fac[i+2];
	}
	NTT(Q);
	for(int i=0;i<m;i++){
		NTT(G);
		for(int j=0;j<len;j++){
			F[j]=mul(Q[j],G[j]);
		}
		INTT(F);
		for(int j=0;j<len;j++){
			if(j>n){
				F[j]=0;
				G[j]=0;
			}
			else{
				F[j]=mul(F[j],fac[j+2]);
				F[j]=add(F[j],mul(P[j],add(C(2,j),add(C(1,j),C(0,j)))));
				P[j]=F[j];
				G[j]=mul(F[j],inv_fac[j]%Mod);
			}
		}
	}
	for(int i=0;i<=n;i++){
		ans=add(ans,mul(C(i,n),F[i]));
	}		
	printf("%d\n",ans);
	return 0;
}