#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[18][5][5][5][5][5][5][5];
int f[10][10];
int a[7];
int b[7];
int pts[5]={0,0,60,70,80};
int test;

int main(void){
	scanf("%d",&test);
	for(int tester=0;tester<test;tester++){
		memset(dp,-1,sizeof(dp));
		memset(f,0,sizeof(f));
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)scanf("%d",&f[j][i]);
		}
		dp[0][f[0][0]][f[1][0]][f[2][0]][f[3][0]][f[4][0]][f[0][1]][f[1][1]]=0;
		for(int i=0;i<16;i++){
			for(a[0]=0;a[0]<=4;a[0]++){
				for(a[1]=0;a[1]<=4;a[1]++){
					for(a[2]=0;a[2]<=4;a[2]++){
						for(a[3]=0;a[3]<=4;a[3]++){
							for(a[4]=0;a[4]<=4;a[4]++){
								for(a[5]=0;a[5]<=4;a[5]++){
									for(a[6]=0;a[6]<=4;a[6]++){
										if(dp[i][a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]>=0){
											for(int j=0;j<7;j++)b[j]=a[j];
											for(int j=0;j<5;j++){
												for(int k=0;k<=1;k++){
													if(b[k]!=0){
														b[k]++;
														if(b[k]==5)b[k]=1;
													}
												}
												for(int k=5;k<=6;k++){
													if(b[k]!=0){
														b[k]++;
														if(b[k]==5)b[k]=1;
													}
												}
												if(i%4==3){
													dp[i+1][b[2]][b[3]][b[4]][b[5]][b[6]][f[0][(i+1)/4+1]][f[1][(i+1)/4+1]]=max(dp[i+1][b[2]][b[3]][b[4]][b[5]][b[6]][f[0][(i+1)/4+1]][f[1][(i+1)/4+1]],dp[i][a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]+pts[b[0]]+pts[b[1]]);
												}else{
													int nx=(i+2)%4;
													if(nx==0)nx=4;
													dp[i+1][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][f[nx][i/4+1]]=max(dp[i+1][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][f[nx][i/4+1]],dp[i][a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]+pts[b[0]]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		int res=0;
		for(a[0]=0;a[0]<=4;a[0]++){
			for(a[1]=0;a[1]<=4;a[1]++){
				for(a[2]=0;a[2]<=4;a[2]++){
					for(a[3]=0;a[3]<=4;a[3]++){
						for(a[4]=0;a[4]<=4;a[4]++){
							for(a[5]=0;a[5]<=4;a[5]++){
								for(a[6]=0;a[6]<=4;a[6]++){
									if(dp[16][a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]>=0)res=max(res,dp[16][a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]+pts[a[0]]+pts[a[1]]+pts[a[2]]+pts[a[3]]+pts[a[4]]);
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}