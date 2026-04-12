#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>
#include<map>
#include<queue>

using namespace std;

typedef pair<int,int> pii;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<=k;i++)
#define in(i,j,k) ((i)>=(j)&&(i)<=(k))

int main(){
	int d[15][15];
	int n,cnt,f;
	int x,y;
	for(;;){
		scanf("%d",&n);
		if(!n)break;
		rep(i,n)rep(j,n)d[i][j]=0;
		cnt=0;
		x=n/2;
		y=n/2+1;
		while(cnt<n*n){
			f=0;
			while(d[x][y]>0){
				y=y==n-1?0:y+1;
				if(f){
					x=x==0?n-1:x-1;
					continue;
				}
				f=1;
				x=x==n-1?0:x+1;
			}
			d[x][y]=++cnt;
		}
		rep(i,n){rep(j,n)printf("%4d",d[j][i]);puts("");}
	}
	return 0;
}