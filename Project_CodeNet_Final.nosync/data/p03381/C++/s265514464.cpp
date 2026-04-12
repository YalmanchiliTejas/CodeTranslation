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

struct num_t {
	int idnum;
	int num;
	int bl;
} ;

int compare_num(const void *a, const void *b) {
	struct num_t *A = (struct num_t *)a;
	struct num_t *B = (struct num_t *)b;
	if(A->num - B->num >0){
		return 1;
	}else if(A->num - B->num >0){
		return -1;
	}else{
		return 0;
	}
}

int compare_idnum(const void *a, const void *b) {
	struct num_t *A = (struct num_t *)a;
	struct num_t *B = (struct num_t *)b;
	if(A->idnum - B->idnum >0){
		return 1;
	}else if(A->idnum - B->idnum >0){
		return -1;
	}else{
		return 0;
	}
}

int main(void)
{
	//変数の宣言
	int n;
	static struct num_t x[200010];
	int t;

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;



	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&t);
//		scanf_s("%d",&t);
		x[i].idnum=i;
		x[i].num=t;
	}

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	qsort(x,n,sizeof(num_t),compare_num);

	for(i=0;i<n;i++){
		if(i<n/2){
			x[i].bl=1;
		}else{
			x[i].bl=0;
		}
	}

	temp1=x[n/2-1].num;
	temp2=x[n/2].num;

	qsort(x,n,sizeof(num_t),compare_idnum);

	for(i=0;i<n;i++){
		if(x[i].bl==1){
			printf("%d\n",temp2);
		}else{
			printf("%d\n",temp1);
		}
	}

	//	printf("計算部分終了\n");

	//出力

	//printf("%lld",temp1*temp2);

	//	printf("結果の出力終了\n");


	return 0;
}

