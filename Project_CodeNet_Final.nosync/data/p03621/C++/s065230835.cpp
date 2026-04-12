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
