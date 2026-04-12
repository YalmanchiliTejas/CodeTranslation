/*
    Author  :Ninnin
    School  :KVIS
    Language:CPP
    Problem :Runnning median
*/
#include "bits/stdc++.h"
#define MAXN 200020
using namespace std;
int dp[MAXN],input[MAXN];
int lendif(int a,int b){
	if(a>b) return a-b;
	return b-a;
}
int main()
{
	int N,med1,med2;
	scanf("%d",&N);
    for(int i=0;i<N;i++){
		scanf("%d",&input[i]);
		dp[i]=input[i];
	}
	sort(dp,dp+N);
	med1=dp[N/2];
	med2=dp[(N/2)-1];
	//for(int i=0;i<N;i++)	printf("%d %d\n",dp[i],i);
	for(int i=0;i<N;i++){
		int len1=lendif(med1,input[i]),len2=lendif(med2,input[i]);
		if(len1>len2){
			printf("%d\n",med1);
		}else{
			printf("%d\n",med2);
		}
	}
    return 0;
}
