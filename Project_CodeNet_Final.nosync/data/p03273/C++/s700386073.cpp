#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdio>
#include<queue>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
#define MAXN 100
#define INF 0x3f3f3f3f
int hang[MAXN+5],lie[MAXN+5];
char str[MAXN+5][MAXN+5];
int main(){
	int h=read(),w=read();
	for(int i=1;i<=h;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			hang[i]+=(str[i][j]=='#'?1:0);
	for(int j=1;j<=w;j++)
		for(int i=1;i<=h;i++)
			lie[j]+=(str[i][j]=='#'?1:0);
	//printf("%d %d\n",h-ans1,w-ans2);
	for(int i=1;i<=h;i++){
		if(!hang[i]) continue;
		for(int j=1;j<=w;j++)
			if(lie[j]) printf("%c",str[i][j]);
		puts("");
	}
	return 0;
}