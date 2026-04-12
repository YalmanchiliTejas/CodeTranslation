#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<functional>
#include<stack>
#include<list>
#include<set>
#include<deque>
#include<climits>
using namespace std;

int N;

void Make(int fld[][15],int y,int x,int num){
	//printf("%d:%d,%d fld[y][x]=%d\n",num,y,x,fld[y][x]);
	if(num>N*N) return;
	if(fld[y][x]==-1){
		fld[y][x] = num;
		Make(fld,(y+1)%N,(x+1)%N,num+1);
	}
	else{
		Make(fld,(y+1)%N,(x-1+N)%N,num);
	}
}

int main(){
	while(cin>>N,N){
		int fld[15][15];
		fill(fld[0],fld[0]+15*15,-1);
		Make(fld,N/2+1,N/2,1);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%4d",fld[i][j]);
			}puts("");
		}
	}
	return 0;
}