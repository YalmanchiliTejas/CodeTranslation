#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#define LL long long
const int M=4000005;
const int N=105;
using namespace std;

int n,m,A[N],B[N];
char a[N][N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n");
		A[i]=0;
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
			if(a[i][j]=='#')A[i]=B[j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!A[i])continue;
		for(int j=1;j<=m;j++){
			if(B[j])printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
