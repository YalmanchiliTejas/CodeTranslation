#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100010;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int tot,h[N];
bool f[N][2];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

bool bz[N];
int fa[N];

void dfs(int x){
	bz[x]=1;
	f[x][0]=1;
	int cnt=0,s=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (!bz[e[p].x]){
		fa[e[p].x]=x;
		dfs(e[p].x);
		f[x][0]&=f[e[p].x][1];
		s++;
		if (f[e[p].x][1])cnt++;
	}
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x&&f[e[p].x][0]){
		if ((cnt-f[e[p].x][1])==s-1)f[x][1]=1;
	}
}

int main(){
	n=get();
	fo(i,1,n-1){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	dfs(1);
	if (f[1][1])printf("Second\n");
	else printf("First\n");
	return 0;
}