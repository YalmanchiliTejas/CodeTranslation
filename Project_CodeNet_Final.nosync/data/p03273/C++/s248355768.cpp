#include<iostream>
#include<cstdio>
#define rg register
#define il inline
#define ll long long
#define maxn 500005
using namespace std;
il int read(){rg int x = 0 ,w = 1;char ch = getchar();while (ch < '0' || ch > '9'){if (ch == '-') w = -1;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x<<3) + (x<<1) + ch - '0';ch = getchar();}return x * w;}
struct edge{
	int to,next;	
}e[maxn << 1];
int head[maxn] , cnt , dis[maxn];
bool vis[300][300];
char ch[300][300];
int main(){
	rg int a = read() , b = read();
	char tmp;
	for (rg int i = 1; i <= a;++i)
			scanf("%s",ch[i]);	
	for (rg int i = 1;i <= a;++i){
		bool ok = 1;
		for (rg int j = 0;j < b;++j){
			if (ch[i][j] != '.'){
				ok = 0;break;
			}
		}
		if (!ok) continue;
		for (rg int j = 0;j < b;++j){
			vis[i][j] = 1;
		}
	}
	for (rg int j = 0;j < b;++j){
		bool ok = 1;
		for (rg int i = 1;i <= a;++i){
			if (ch[i][j] != '.'){
				ok = 0;break;
			}
		}	
		if (!ok) continue;
		for (rg int i = 1;i <= a;++i){
			vis[i][j] = 1;
		}
	}
	for (rg int i = 1;i <= a;++i){
		bool ok = 0;
		for (rg int j = 0;j < b;++j)
				if (!vis[i][j]) {cout<<ch[i][j]; ok = 1;}
		if (ok) putchar('\n');			
	}	
	return 0;	
}