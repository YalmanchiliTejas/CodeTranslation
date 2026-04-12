#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct node {
	int to, next;
} edge[MAXN*2];
int head[MAXN], top = 0;
inline void push(int i, int j)
{ edge[++top] = (node){j, head[i]}, head[i] = top; }

int n, u, v, d[MAXN];
int vis[MAXN];
queue<int> que;

#define NEW 0
#define LEAF 1
#define DEL 2
#define CHO 3

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	if (n == 1) {
		puts("First");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		push(u, v), push(v, u), d[u]++, d[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == 1)
			vis[i] = LEAF, que.push(i);
	while (!que.empty()) {
		int nd = que.front(); que.pop();
		if (vis[nd] == LEAF) {
			vis[nd] = DEL;
			int flag = 1;
			for (int i = head[nd]; i; i = edge[i].next) {
				int to = edge[i].to;
				if (vis[to] == CHO) {
					puts("First");
					return 0;
				} else if (vis[to] == LEAF) flag = 0, vis[to] = DEL;
				else if (vis[to] == NEW) {
					d[to]--;
					vis[to] = CHO, que.push(to);
					flag = 0;
				}
			}
			if (flag) {
				puts("First");
				return 0;
			}
		} else if (vis[nd] == CHO) {
			vis[nd] = DEL;
			for (int i = head[nd]; i; i = edge[i].next) {
				int to = edge[i].to;
				if (vis[to] == NEW) {
					if ((--d[to]) == 1) vis[to] = LEAF, que.push(to);
				} 
								    
			}
		} else if (vis[nd] == DEL) continue;
	}
	puts("Second");
	return 0;
}
