#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=10;
int n,m,mp[maxn][maxn];
char s[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	#endif
	n=rd(); m=rd();
	go(i,n+1,1){
		scanf("%s",s+1);
		go(j,m+1,1) mp[i][j]=s[j]=='#';
	}
	go(i,n+1,1) go(j,m+1,1)
		if(mp[i][j]){
			go(x,i,1) go(y,m+1,j+1)
			if(mp[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	return 0;
}//Faze
