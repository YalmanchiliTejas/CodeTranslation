#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;


vector<int> g[10];
int visit[10];
int ans, n, m;

void f(int v, int cnt) {
    //printf("v = %d, cnt = %d\n", v, cnt);
    if (cnt == n) {
        ans++;
        return;
    }
    
    
    for (int i = 0; i < g[v].size(); i++) {
        if (visit[g[v][i]] == false ) {
            visit[g[v][i]] = true;
            f(g[v][i], cnt+1);
            visit[g[v][i]] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    visit[1] = true;
    f(1, 1);
    cout << ans << endl;
    
    
    
    return 0;
}
