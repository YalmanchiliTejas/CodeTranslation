//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <bitset>
#include <numeric>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);j++)
#define frk(n) for(k=0;k<(n);k++)
#define frl(n) for(l=0;l<(n);l++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvvd vector<vector<vector<double>>>


#define int long long

using namespace std;


const int MAX = 510000;

ll mod_inverse(int a,int M){
	int x=M-2;
	ll temp=a;
	ll ret=1;
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

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed compare_int(const void *a, const void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}


int gcd(int a,int b){
	while(1==1){
		if(a==0||b==0){
			return a+b;
		}else if(a>b){
			a %= b;
		}else{
			b %= a;
		}
	}
}

signed main(void)
{
	//変数の宣言
	int n,m,q;
	int h,w;
	static int a[200010];
	static int s[100010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	vector<int> vec;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	static char stemp[100010];
	vvi graph;

	//データの読み込み


	scanf("%lld",&n);
	//scanf_s("%lld",&n);


	//scanf("%s",&s);
	//scanf_s("%s",&s,200010);


	for(i=0;i<n;i++){
	scanf("%lld",&a[i]);
	//scanf_s("%lld",&a[i]);
	}

	/*for(i=0;i<q;i++){
	//scanf("%d",&s[i]);
	scanf_s("%d",&s[i]);
	}*/



	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	//	clock_t start=clock();
	//	COMinit();

	vi vsum(n,0);
	max=0;

	if(n%2==1){
		for(i=0;i<n;i=i+2){
			if(i==0){
				vsum[0]=-a[0];
				max=vsum[0];
			}else{
				vsum[i]=-a[i]+max(vsum[i-2]+a[i-1],0);
				max=max(max,vsum[i]);
			}
		}

		for(i=0;i<n;i=i+2){
			ans=ans+a[i];
		}

		printf("%lld",ans+max);
	}else{
		for(i=1;i<n;i=i+2){
			if(i==1){
				vsum[1]=a[0]-a[1];
				max=max(0,vsum[1]);
			}else{
				vsum[i] = vsum[i-2]+a[i-1]-a[i];
				max=max(max,vsum[i]);
			}
		}

		for(i=1;i<n;i=i+2){
			ans=ans+a[i];
		}

		printf("%lld",ans+max);
	}

	//	clock_t end=clock();

	//	printf("計算部分終了\n");

	//出力

	//printf("%d",(d[i-1][j-1]+1)/2);

	//	printf("time=%lf",(double)(end-start)/CLOCKS_PER_SEC);
	//	printf("結果の出力終了\n");

	return 0;
}

