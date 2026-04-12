#include <bits/stdc++.h>
using namespace std;

int N;
bool leaf[100005];
vector<int> v[100005];

void dfs(int x, int p) {
    int cnt = 0;
    for(int it : v[x]) {
        if(it == p) continue;
        dfs(it, x);
        if(leaf[it]) cnt++;
    }
    if(cnt > 1) { puts("First"); exit(0); }
    leaf[x] = !cnt;
}

int main() {
    scanf("%d", &N);
    if(N & 1) return puts("First"),0;
    for(int i=1, x, y; i<N; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    puts("Second");
}
