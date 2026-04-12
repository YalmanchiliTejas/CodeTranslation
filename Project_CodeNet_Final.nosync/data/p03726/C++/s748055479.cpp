#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Road{
	int e,next;
}r[410000];int R[210000],num;
int n,f[210000];

void addr(int x,int y){
	r[++num]=(Road){y,R[x]};
	R[x]=num;
}

void dp(int u,int fa){
	for(int i=R[u];i;i=r[i].next){
		int v=r[i].e;
		if(v==fa)continue;
		dp(v,u);
		if(f[u]==0&&f[v]==0)f[v]=f[u]=1;
	}
}

int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		addr(x,y);addr(y,x);
	}dp(1,0);
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			printf("First\n");
			return 0;
		}
	}printf("Second\n");
	return 0;
}