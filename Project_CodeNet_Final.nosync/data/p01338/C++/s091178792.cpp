#include<stdio.h>
#include<algorithm>
using namespace std;
int b[5][5];
int dp[6][1<<8];
int sc[]={0,60,70,80};
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++){
				scanf("%d",&b[i][j]);
				b[i][j]--;
			}
		for(int i=0;i<6;i++){
			//for(int j=0;j<6;j++)
				for(int k=0;k<(1<<8);k++)
					dp[i][k]=-999999999;
		}
		dp[0][0]=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<(1<<8);j++){
				if(dp[i][j]<0)continue;
				for(int k=0;k<(1<<8);k++){
					if(i==4&&k)break;
					int gs=0;
					if(~b[i][0])gs+=sc[(b[i][0]+(j%4)+(k%4))%4];
					if(~b[i][1])gs+=sc[(b[i][1]+(j%4)+(j%16/4)+(k%4)+(k%16/4))%4];
					if(~b[i][2])gs+=sc[(b[i][2]+(j%16/4)+(j%64/16)+(k%16/4)+(k%64/16))%4];
					if(~b[i][3])gs+=sc[(b[i][3]+(j%64/16)+(j%256/64)+(k%64/16)+(k%256/64))%4];
					if(~b[i][4])gs+=sc[(b[i][4]+(j%256/64)+(k%256/64))%4];
					
					dp[i+1][k]=max(dp[i+1][k],dp[i][j]+gs);
				}
			}
		}
		printf("%d\n",dp[5][0]);
	}
}