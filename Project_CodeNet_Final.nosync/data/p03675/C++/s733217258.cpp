#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#include<stdlib.h>
#define M 500005
#define N 100
#define ll long long
#define oo 1000000000
#define mod 555555555
using namespace std;
int n,m;
int B[M],A[M],L,R;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	L=250000;
	B[L]=A[1];
	R=250000;
	for(i=2;i<=n;i++){
		if(i%2==0){
			B[++R]=A[i];
		}else B[--L]=A[i];
	}
	if(i%2==1){
		for(i=R;i>=L;i--){
			printf("%d ",B[i]);
			
		}
	}else {
		for(i=L;i<=R;i++){
			printf("%d ",B[i]);
			
		}
	}
	return 0;
}
	