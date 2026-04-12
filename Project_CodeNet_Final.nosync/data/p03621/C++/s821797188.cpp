#include<cstdio>
const int mod=998244353;
char str[2][100010];
int fac[100010],ifac[100010],S[100010];
long long inv(int a,int p=mod){return a==1?1:(1+p*(a-inv(p%a,a)))/a%p;}
int main(){
	scanf("%s%s",str[0],str[1]);
	int A=0,B=0;
	for(int i=0;str[0][i];i++)if(str[0][i]=='1'){
		if(str[1][i]=='1')A++;
		else B++;
	}
	for(int i=*fac=1;i<=A+B;i++)fac[i]=fac[i-1]*1ll*i%mod;
	ifac[A+B]=inv(fac[A+B]);
	for(int i=A+B;i;i--)ifac[i-1]=ifac[i]*1ll*i%mod;
	int s=0;
	for(int i=0;i<=A+B;i++){
		for(int j=i<B?i:B;j;j--)S[j]=(S[j-1]+1ll*S[j]*j)%mod;
		S[0]=!i;
		if(i>=B)s=(s+1ll*S[B]*ifac[i])%mod;
	}
	s=1ll*s*fac[A]%mod*fac[A+B]%mod*fac[B]%mod*fac[B]%mod;
	printf("%d\n",s);
}