/*
#include <cstdio>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=10000;
const int Mod=998244353;
int f[Maxn+5][Maxn+5];
int n,k;
char a[Maxn+5],b[Maxn+5];
int s_1,s_2;
int frac[Maxn+5],inv_f[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%s",a+1);
	scanf("%s",b+1);
	while(a[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		if(a[i]=='1'){
			k++;
		}
		if(a[i]=='1'&&b[i]=='1'){
			s_1++;
		}
		else if(a[i]=='1'){
			s_2++;
		}
	}
	f[0][0]=1;
	for(int i=0;i<=s_1;i++){
		for(int j=1;j<=s_2;j++){
			if(i==0&&j==0){
				continue;
			}
			f[i][j]=(f[i][j]+1ll*f[i][j-1]*j%Mod*j)%Mod;
			if(i>0){
				f[i][j]=(f[i][j]+1ll*f[i-1][j]*i%Mod*j)%Mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=s_1;i++){
		ans=(ans+1ll*f[s_1-i][s_2]*frac[i]%Mod*frac[i]%Mod*C(s_1,i)%Mod*C(k,i))%Mod;
	}
	printf("%d\n",ans);
	return 0;
}
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=40000;
const int G=3;
const int Mod=998244353;
int n,m,len;
char a[Maxn+5],b[Maxn+5];
void NTT(int *a,int flag,int n){
	static int R[Maxn+5];
	int len=1,L=0;
	while(len<n){
		len<<=1;
		L++;
	}
	for(int i=0;i<len;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	}
	for(int i=0;i<len;i++){
		if(i<R[i]){
			swap(a[i],a[R[i]]);
		}
	}
	for(int j=1;j<len;j<<=1){
		int T=quick_power(G,(Mod-1)/(j<<1),Mod);
		for(int k=0;k<len;k+=(j<<1)){
			for(int l=0,t=1;l<j;l++,t=1ll*t*T%Mod){
				int Nx=a[k+l],Ny=1ll*t*a[k+l+j]%Mod;
				a[k+l]=(Nx+Ny)%Mod;
				a[k+l+j]=(Nx-Ny+Mod)%Mod;
			}
		}
	}
	if(flag==-1){
		reverse(a+1,a+len);
		for(int i=0,t=quick_power(len,Mod-2,Mod);i<len;i++){
			a[i]=1ll*a[i]*t%Mod;
		}
	}
}
void find_inv(int *a,int *b,int len){
	static int c[Maxn+5],d[Maxn+5];
	if(len==1){
		b[0]=quick_power(a[0],Mod-2,Mod);
		return;
	}
	find_inv(a,b,len>>1);
	for(int i=0;i<len;i++){
		c[i]=a[i];
		d[i]=b[i];
	}
	for(int i=len;i<(len<<1);i++){
		c[i]=d[i]=0;
	}
	NTT(c,1,len<<1);
	NTT(d,1,len<<1);
	for(int i=0;i<(len<<1);i++){
		d[i]=1ll*d[i]*d[i]%Mod*c[i]%Mod;
	}
	NTT(d,-1,len<<1);
	for(int i=0;i<len;i++){
		b[i]=((b[i]<<1)%Mod-d[i]+Mod)%Mod;
	}
	for(int i=len;i<(len<<1);i++){
		b[i]=0;
	}
}
void find_dev(int *a,int len){
	for(int i=0;i<len;i++){
		a[i]=1ll*(i+1)*a[i+1]%Mod;
	}
	a[len-1]=0;
}
void find_dev_inv(int *a,int len){
	for(int i=len-1;i>0;i--){
		a[i]=1ll*quick_power(i,Mod-2,Mod)*a[i-1]%Mod;
	}
	a[0]=0;
}
void find_ln(int *a,int *b,int n){
	static int c[Maxn+5];
	for(int i=0;i<n;i++){
		c[i]=a[i];
	}
	find_dev(c,n);
	int len=1;
	while(len<n){
		len<<=1;
	}
	find_inv(a,b,len);
	for(int i=n;i<len;i++){
		b[i]=0;
	}
	for(int i=len;i<(len<<1);i++){
		b[i]=c[i]=0;
	}
	NTT(b,1,len<<1);
	NTT(c,1,len<<1);
	for(int i=0;i<(len<<1);i++){
		b[i]=1ll*b[i]*c[i]%Mod;
	}
	NTT(b,-1,len<<1);
	find_dev_inv(b,len<<1);
	for(int i=n;i<(len<<1);i++){
		b[i]=0;
	}
}
void find_exp(int *a,int *b,int len){
	static int c[Maxn+5];
	if(len==1){
		b[0]=1;
		return;
	}
	find_exp(a,b,len>>1);
	find_ln(b,c,len);
	c[0]=(a[0]+1-c[0]+Mod)%Mod;
	for(int i=1;i<len;i++){
		c[i]=(a[i]-c[i]+Mod)%Mod;
	}
	for(int i=len;i<(len<<1);i++){
		b[i]=c[i]=0;
	}
	NTT(b,1,len<<1);
	NTT(c,1,len<<1);
	for(int i=0;i<(len<<1);i++){
		b[i]=1ll*b[i]*c[i]%Mod;
	}
	NTT(b,-1,len<<1);
	for(int i=len;i<(len<<1);i++){
		b[i]=c[i]=0;
	}
}
int f[Maxn+5],g[Maxn+5];
int frac[Maxn+5],inv_f[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int main(){
	init();
	scanf("%s",a+1);
	scanf("%s",b+1);
	while(a[++len]!='\0');
	for(int i=1;i<=len;i++){
		if(a[i]=='1'){
			n++;
			if(b[i]=='0'){
				m++;
			}
		}
	}
	for(int i=0;i<=n-m;i++){
		f[i]=inv_f[i+1];
	}
	int len=1;
	while(len<=n-m){
		len<<=1;
	}
	find_ln(f,g,len);
	memset(f,0,sizeof f);
	for(int i=0;i<=n-m;i++){
		f[i]=1ll*g[i]*m%Mod;
	}
	memset(g,0,sizeof g);
	find_exp(f,g,len);
	int ans=0;
	for(int i=0;i<=n-m;i++){
		f[i]=g[i];
		ans=(ans+f[i])%Mod;
	}
	ans=1ll*ans*frac[m]%Mod*frac[n-m]%Mod*frac[n]%Mod;
	printf("%d\n",ans);
	return 0;
}
