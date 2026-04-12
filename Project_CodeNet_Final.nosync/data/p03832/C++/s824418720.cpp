
//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define swap(p,q) r=(p);(p)=(q);(q)=r
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007//10^9+7
#define PI acos(-1)

using namespace std;

ll int mod_inverse(int a,int M){
	int x=M-2;
	ll int temp=a;
	ll int ret=1;
	//a^(MOD-1)==1(mod MOD)を利用
	//a^-1==a^(MOD-2) (mod MOD)を繰り返し二乗法で求める

	while(x!=0){
		if(x%2==1){
			ret=(ret*temp)%M;
		}
		temp=(temp*temp)%M;
		x=x/2;
	}
	return ret;
}

int main(void)
{
	//変数の宣言
	int n,a,b,c,d;
	static ll int dp[1010][1010];
	static ll int factorial[1010];
	static ll int ifp[1010][1010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	int ok,ng;



	//データの読み込み


	scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
//	scanf_s("%d %d %d %d %d",&n,&a,&b,&c,&d);


/*	for(i=0;i<m;i++){
//		scanf("%d %d %d",&u,&v,&s);
		scanf_s("%d %d %d",&u,&v,&s);
	}*/

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	factorial[0]=1;
	for(i=1;i<=n;i++){
		factorial[i]=factorial[i-1]*i%MOD;
	}

	for(i=0;i<=n;i++){
		temp1=factorial[i];
		temp=1;
		for(j=0;j<=n;j++){
			ifp[i][j]=mod_inverse(temp,MOD);
			temp=(temp*temp1)%MOD;
		}
	}


	for(i=0;i<1010;i++){
		for(j=0;j<1010;j++){
			dp[i][j]=0;
		}
	}

	dp[a-1][0]=1;
	for(i=a;i<=b;i++){
		for(j=0;j<=n;j++){
			k=0;
			while(j>=i*k&&(k==0||(c<=k&&k<=d))){
				temp=(dp[i-1][j-i*k]*factorial[n-j+i*k])%MOD;
				temp=(temp*ifp[n-j][1])%MOD;
				temp=(temp*ifp[i][k])%MOD;
				temp=(temp*ifp[k][1])%MOD;
				dp[i][j]=(dp[i][j]+temp)%MOD;
				if(k==0){
					k=c;
				}else{
					k++;
				}
			}
		}
	}


	//	printf("計算部分終了\n");

	//出力
	
/*	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
		}
		printf("\n");
	}*/


	printf("%lld",dp[b][n]);
	

	//	printf("結果の出力終了\n");


	return 0;
}

