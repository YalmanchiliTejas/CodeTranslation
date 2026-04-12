//Created Time:2019年12月01日 星期日 14时56分42秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 100005

using namespace std;

struct edge{
	int to, nxt;
}e[N << 1];

int n, cnt;
int fir[N], deg[N], tmp[N], flag[N];
bool vis[N];

queue < int > que;

int read();
void add(int ,int);

int main(){
	n = read();
	for(int i = 1; i < n; ++i){
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	memcpy(tmp, deg, sizeof tmp);
	for(int i = 1; i <= n; ++i)
		if(deg[i] == 1) que.push(i);
	while(!que.empty()){
		int u = que.front(); que.pop(); 
		if(vis[u]) continue; vis[u] = true;
		bool flag = false;
		for(int i = fir[u]; i; i = e[i].nxt){
			int v = e[i].to; if(vis[v]) continue; 
			flag = true; vis[v] = true;
			for(int j = fir[v]; j; j = e[j].nxt){
				int p = e[j].to; if(vis[p]) continue;
				--deg[p]; if(deg[p] == 1) que.push(p);
			}
		}
		if(!flag){
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}

int read(){
	int x = 0; char ch = getchar();
	for(; !isdigit(ch); ch = getchar());
	for(; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
	return x;
}

void add(int u, int v){
	e[++cnt] = (edge){v, fir[u]}; fir[u] = cnt; ++deg[u];
	return ;
}
