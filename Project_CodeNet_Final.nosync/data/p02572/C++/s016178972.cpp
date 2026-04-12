#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
const int Mod=1000000007;
int n;
int a[Maxn+5];
int sum[Maxn+5];
int main(){
	read(n);
	int ans=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		sum[i]=(sum[i-1]+a[i])%Mod;
		ans=(ans+1ll*a[i]*sum[i-1])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}
