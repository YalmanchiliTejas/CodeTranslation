#include<cstdio>
#include<cstring>
#define N 100005
#define mod 1000000007
int n;
char c[N];
int dp[N][105][2];
int D;
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int main(){
	scanf("%s%d",c,&D);
	n=strlen(c);
	dp[0][0][1]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<D;++j){
			for(int f=0;f<2;++f){
				for(int k=0;k<=(f?c[i]-'0':9);++k){
					add(dp[i+1][(j+k)%D][f?k==c[i]-'0':0],dp[i][j][f]);
				}
			}
		}
	}
	printf("%d\n",(dp[n][0][0]+dp[n][0][1]+mod-1)%mod);
	return 0;
}
