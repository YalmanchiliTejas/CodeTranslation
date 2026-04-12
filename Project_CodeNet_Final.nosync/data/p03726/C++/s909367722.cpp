#include<bits/stdc++.h>
#define reg register
#define maxn 500001
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int nt[maxn << 1], go[maxn << 1], fi[maxn << 1], vis[maxn << 1], deg[maxn], cnt, n;
queue <int> Q;
void add(int u, int v){
    nt[++cnt] = fi[u]; fi[u] = cnt; go[cnt] = v;
}
int main()
{
    n = read();
    for(int i = 1; i < n; i++){
        int x = read(), y = read();
        add(x, y); add(y, x);
        deg[x]++; deg[y]++;
    } 
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) Q.push(i); 
    }
    while(!Q.empty()){
        int x = Q.front(); Q.pop(); vis[x] = 1;
        for(int i = fi[x]; i; i = nt[i]){
            int v = go[i];  if(vis[v]) continue; 
            vis[v] = 1; deg[v]--; 
            for(int j = fi[v]; j; j = nt[j]){
                int t = go[j]; if(vis[t]) continue; deg[t]--; 
                if(deg[t] == 0) {
                    printf("First\n"); return 0;
                }
                if(deg[t] == 1)  Q.push(t);
            } 
            break;
        }
    }
    printf("Second\n");
}