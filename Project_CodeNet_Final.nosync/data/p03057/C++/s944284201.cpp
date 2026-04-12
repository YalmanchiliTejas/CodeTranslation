#include<bits/stdc++.h>
const int mo=1e9+7,N=2e5+5;
int n,m,i,j,ans,lm=N,f[N],s[N];
char c[N];
int main(){
	scanf("%d%d%s",&n,&m,c+1);
	for(i=1;c[i]==c[1];++i);
	if(i>m){
		static int f[N][2];
		f[0][0]=1;
		for(i=1;i<=n;++i)f[i][0]=(f[i-1][0]+f[i-1][1])%mo,f[i][1]=f[i-1][0];
		ans=f[n][0];
		memset(f,0,sizeof f);
		f[0][1]=1;
		for(i=1;i<=n;++i)f[i][0]=(f[i-1][0]+f[i-1][1])%mo,f[i][1]=f[i-1][0];
		ans=(ans+f[n][1])%mo;
	}else{
		lm=i&1?i:i-1;
		for(;i<=m;i=j){
			for(j=i+1;c[j]==c[1];++j);
			if(j<=m && (j-i-1)%2==1)lm=std::min(lm,j-i-1);
		}
		if(n&1){puts("0");return 0;}
		lm-=lm%2==0;lm=lm+1>>1;
		s[0]=f[0]=1;
		for(i=1;i<=n;++i)f[i]=(s[i-1]+mo-(i>lm?s[i-lm-1]:0))%mo,s[i]=(s[i-1]+f[i])%mo;
		for(i=1;i<=lm*2-1 && i+1<=n;i+=2)ans=(ans+1ll*(i+1)*f[n-i-1>>1])%mo;
	}
	printf("%d\n",ans);
	return 0;
}