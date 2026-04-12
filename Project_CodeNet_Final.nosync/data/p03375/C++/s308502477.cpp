#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c[3005][3005],s[3005][3005],p2[3000*3000+5],pp2[3005];
int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			c[i][j]=(!j||j==i?1:c[i-1][j-1]+c[i-1][j])%p;
	s[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=(1ll*j*s[i-1][j]+s[i-1][j-1])%p;
	p2[0]=1; 
	for(int i=1;i<=n*n;i++)p2[i]=p2[i-1]*2%p;
	pp2[0]=2;
	for(int i=1;i<=n;i++)pp2[i]=1ll*pp2[i-1]*pp2[i-1]%p;
	int ans=0;
	for(int i=0;i<=n;i++){
		int res=0;
		for(int j=0;j<=i;j++)res=(res+1ll*s[i+1][j+1]*p2[(n-i)*j])%p;
		// printf("%d\n",res);
		ans=((ans+(i&1?-1ll:1ll)*c[n][i]*res%p*pp2[n-i])%p+p)%p;
	}
	printf("%d\n",ans);
}