#include<bits/stdc++.h>
const int N=3005;
int n,mo,i,j,k,s[N][N],C[N][N],m1[N],m2[N],ans,x,y;
int main(){
	scanf("%d%d",&n,&mo);
	for(i=*m1=1,*m2=2;i<=n;++i)m1[i]=2*m1[i-1]%mo,m2[i]=1ll*m2[i-1]*m2[i-1]%mo;
	for(i=**C=1;i<=n;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=1,s[0][0]=1;i<=n;++i)for(s[i][1]=m1[i]-1,s[i][0]=1,j=2;j<=i;++j)
		s[i][j]=(s[i-1][j-1]+s[i-1][j]+1ll*s[i-1][j]*j)%mo;
	for(i=0;i<=n;++i){
		x=0;y=1;
		for(k=0;k<=i;++k)x=(x+1ll*s[i][k]*y)%mo,y=1ll*y*m1[n-i]%mo;
		ans=(ans+1ll*(i&1?mo-C[n][i]:C[n][i])*m2[n-i]%mo*x)%mo;
	}
	printf("%d\n",ans);
	return 0;
}