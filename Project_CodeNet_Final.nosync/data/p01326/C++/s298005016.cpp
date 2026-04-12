#include<stdio.h>
#include<algorithm>
using namespace std;
char str[1100][10];
int mod=1000000;
int dp[1100][5][5];
int t[12];
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++)scanf("%s",str[i]);
		for(int i=0;i<1100;i++)for(int j=0;j<5;j++)for(int k=0;k<5;k++)
			dp[i][j][k]=0;
		dp[a][0][0]=1;
		for(int i=a-1;i>=0;i--){
			for(int j=0;j<12;j++)t[j]=0;
			for(int j=0;j<256;j++){
				bool ok=true;
				for(int k=0;k<8;k++){
					if((j&(1<<k))&&str[i][k]=='0')ok=false;
					if(!(j&(1<<k))&&str[i][k]=='1')ok=false;
				}
				if(ok){
					if(j%2==0)t[0]++;
					else if(j%4==1){
						if(j&4)t[1]++;
						else if(j&8)t[2]++;
						else t[3]++;
					}else if(j%8==3){
						if(j&120)t[4]++;
					}else if(j%16==7){
						if(j&240)t[5]++;
						else t[6]++;
					}else if(j%32==15){
						if(j&224)t[7]++;
						else t[8]++;
					}
				}
			}
		//	for(int j=0;j<9;j++)printf("%d ",t[j]);printf("\n");
			dp[i][0][0]=(dp[i+1][0][0]*t[0]+(dp[i+1][1][0])*t[4]+
			dp[i+1][2][0]*t[5]+dp[i+1][2][1]*(t[5]+t[6])+dp[i+1][3][0]*t[7]+dp[i+1][3][1]*(t[7]+t[8]))%mod;
			dp[i][1][0]=(dp[i+1][0][0]*(t[1]+t[2]+t[3]))%mod;
			dp[i][2][0]=(dp[i+1][1][0]*(t[2]+t[3]))%mod;
			dp[i][2][1]=(dp[i+1][1][0]*t[1])%mod;
			dp[i][3][0]=((dp[i+1][2][0]+dp[i+1][2][1])*t[3])%mod;
			dp[i][3][1]=((dp[i+1][2][0]+dp[i+1][2][1])*(t[1]+t[2]))%mod;
		}
		printf("%d\n",dp[0][0][0]);
	}
}