#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
#define inf 101010;

int n, m, k;
int g[101][101];
int dp[1<<16];
int a[16];
set<int> s;
map<int,int> ma;
queue<int> que;

void bfs(int cnt) {
    queue<int> q2;
    while (!que.empty()) {
        int bit = que.front();
        que.pop();
        
        for (int i = 0; i < k; i++) {
            int nbit = 0;
            for (int j = 0; j < m; j++) {
                int b = 1<<j;
                if (bit & b) {
                    int t = a[j];
                    int u = g[t-1][i];
                    if (s.count(u)) nbit |= 1<<ma[u];
                }
            }
            if (!nbit) {
                dp[0] = cnt+1;
                return;
            }
            else if (dp[nbit] > cnt+1) {
                dp[nbit] = cnt+1;
                q2.push(nbit);
            }
        }
    }
    que = q2;
    bfs(cnt+1);
}

int main(void){
    cin >> n >> m >> k;
    int bit = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        s.insert(a[i]);
        ma[a[i]] = i;
        bit |= 1<<i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < 1<<m; i++) dp[i] = inf;
    que.push(bit);
    bfs(0);
    cout << dp[0] << endl;
}