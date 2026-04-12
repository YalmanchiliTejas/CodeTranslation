#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
int n;
#define Maxn 10000010
int two[Maxn];
int fact[Maxn],inv[Maxn];

inline int Fast_Pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return res;
}
 
inline int C(int i,int j){return 1ll*fact[i]*inv[i-j]%Mod*inv[j]%Mod;}
 
int main(){
	scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%Mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=2;i<=n;++i)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
	int res=Fast_Pow(3,n);
	two[0]=1;
	for(int i=1;i<=n;++i){
		two[i]=two[i-1]+two[i-1];
		if(two[i]>=Mod)two[i]-=Mod;
	}
	for(int i=n/2+1;i<=n;++i)
		res=(res-1ll*C(n,i)*two[n-i+1]%Mod+Mod)%Mod;
	printf("%d\n",res);
	return 0; 
} 