#include <bits/stdc++.h>

using namespace std;

int G[10][10];

struct point {
    int s;
    int cnt;
    bool g[10];
}p, pre, now;

queue<point> q;
int num;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y;
    num = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        G[x][y] = 1;
        G[y][x] = 1;
    }
    for(int i = 1; i <= n; i++) p.g[i] = 1;
    p.s = 1;
    p.cnt = 1;
    p.g[1] = 0;
    q.push(p);
    while(!q.empty()) {
        pre = q.front();
        q.pop();
        int k = pre.s;
        //printf("%d\n", pre.cnt);
        for(int i = 1; i <= n; i++) {
            if(G[i][k] == 1 && pre.g[i] == 1) {
                if(pre.cnt == n - 1) {
                    num++;
                    continue;
                }
                now = pre;
                now.g[i] = 0;
                now.cnt++;
                now.s = i;
                q.push(now);
            }
        }
    }
    printf("%d\n", num);
    return 0;
}
