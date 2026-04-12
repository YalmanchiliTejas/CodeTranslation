#include<bits/stdc++.h>
using namespace std;
int n,mo,ans;
int s[3005][3005];
int c[3005][3005];
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y){
	int ans=1;
	for (int i=x-y+1;i<=x;i++)
		ans=1ll*ans*i%mo;
	for (int i=1;i<=y;i++)
		ans=1ll*ans*power(i,mo-2,mo)%mo;
	return ans;
}
int main(){
	scanf("%d%d",&n,&mo);
	s[0][0]=c[0][0]=1;
	for (int i=1;i<=n+1;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++){
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mo;
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
		}
	}
	for (int ij=0;ij<=n;ij++){
		int tmp=0,v=1,del=power(2,n-ij,mo);;
		for (int k=0;k<=ij;k++){
			tmp=(tmp+1ll*s[ij+1][k+1]*v)%mo;
			v=1ll*v*del%mo;
		}
		tmp=1ll*tmp*power(2,power(2,n-ij,mo-1),mo)%mo;
		tmp=1ll*tmp*c[n][ij]%mo;
		ans=(ans+((ij&1)?mo-tmp:tmp))%mo;
	}
	printf("%d\n",ans);
}