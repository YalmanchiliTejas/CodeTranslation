#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 110;
typedef long long LL;
int N,M;
LL f[SIZEN][2][10];
char str[SIZEN];
LL dfs(int x,bool lim,int k){
	if(k > M)return 0;
	if(x == N+1){
		return k == M;
	}
	if(~f[x][lim][k])return f[x][lim][k];
	f[x][lim][k] = 0;
	int top = lim?str[x]-48:9;
	for(int i = 0;i <= top;i++){
		f[x][lim][k] += dfs(x+1,lim & (i == top),k+(i != 0));
	}
	return f[x][lim][k];
}
int main(){
	scanf("%s",str+1);
	N = strlen(str+1);
	scanf("%d",&M);
	memset(f,-1,sizeof f);
	printf("%lld\n",dfs(1,1,0));
	return 0;
}
/*
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
3
*/