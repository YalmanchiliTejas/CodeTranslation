#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
struct Edge {
    int next, to;
    Edge(int a=0, int b=0) : next(a), to(b) {}
} e[maxn << 1];
int head[maxn], tot = 1;
void Add(int u, int v) {
    e[++tot] = Edge(head[u], v); head[u] = tot;
}

int N, leaf[maxn << 1], vis[maxn << 1];

int Leaf(int p) {
    if(vis[p]) return leaf[p]; vis[p] = 1;
    int x = e[p].to, c = 0;
    for(int i = head[x]; i; i = e[i].next) 
	if(p ^ i ^ 1) c += Leaf(i);
    return leaf[p] = (c == 0);
}
int main() {
    scanf("%d", &N);
    for(int i = 1, u, v; i < N; ++i) {
	scanf("%d %d", &u, &v);
	Add(u, v); Add(v, u);
    }
    bool Win = false;
    for(int x = 1; x <= N; ++x) {
	if(Leaf(x)) continue;
	int c = 0;
	for(int i = head[x]; i; i = e[i].next) c += Leaf(i);
	if(c > 1) Win = true;
    }
    puts(Win ? "First" : "Second");
    return 0;
}
