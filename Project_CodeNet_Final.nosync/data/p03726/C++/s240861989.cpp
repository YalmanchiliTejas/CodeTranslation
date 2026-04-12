#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
inline int read(){
	int sum = 0, t = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') t = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ sum = sum * 10 + ch - '0'; ch = getchar(); }
	return sum * t;
}

int n, nxt[N<<1], fir[N], to[N<<1], cnt;

void add(int x, int y){
	nxt[++cnt] = fir[x]; to[cnt] = y; fir[x] = cnt;
	nxt[++cnt] = fir[y]; to[cnt] = x; fir[y] = cnt;
}

bool f[N][2];

void dfs(int x, int p){
	f[x][0] = true;
	for(int i = fir[x]; i ; i = nxt[i]) if(to[i] != p){
		int y = to[i];
		dfs(y, x);
		f[x][1] = (f[x][1] & f[y][1]) | (f[x][0] & f[y][0]);
		f[x][0] &= f[y][1];
	}
}

int main(){
	n = read();
	for(int i = 1; i < n; i++) add(read(), read());
	dfs(1, 0);
	if(f[1][1]) puts("Second");
	else puts("First");
}
