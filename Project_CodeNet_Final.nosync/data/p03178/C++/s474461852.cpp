#include<cstdio>
#include<cstring>
const int MAXN=10010;
const int MOD=1e9+7;

int n,k;
int f[MAXN][110],ans;
char ch[MAXN];

void upd(int &x,int y){
	x=(x+(y+MOD)%MOD)%MOD;
}
int main() {
	scanf("%s%d",ch+1,&k);n=strlen(ch+1);
	f[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int d=0;d<=9;d++)
			for(int j=0;j<=k;j++)
				upd(f[i][(d+j)%k],f[i-1][j]);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<ch[i]-'0';j++)
			upd(ans,f[n-i+1][(-(sum+j)%k+k)%k]);
		sum=(sum+ch[i]-'0')%k;
	}
	if(sum)
		upd(ans,-1);
	printf("%d\n",ans);
	return 0;
}