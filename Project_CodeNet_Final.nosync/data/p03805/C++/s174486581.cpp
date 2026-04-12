#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1010, MAXE = 1000010;

struct edge { int u, v, next; } g[MAXE];

int n, m;
int head[MAXV], idx;

int main(int argc, char *argv[])
{

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    idx = 0;
    memset(head, -1, sizeof(head));
    
    cin >> n >> m;
    
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        
        g[idx] = edge{u, v, head[u]};
        head[u] = idx++;
        
        g[idx] = edge{v, u, head[v]};
        head[v] = idx++;
        
    }
    
    int permutation[8], cases = 0;
    iota(permutation, permutation + n, 0);
    
    do {
        int cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            int ii = permutation[i];
            bool match = false;
            for (int j = head[ii]; ~j; j = g[j].next){
                if (g[j].v == permutation[i + 1]) {
                    match = true;
                    break;
                }
            }
            if (!match) {
                break;
            }
            cnt++;
        }
        if (cnt == n) {
            cases++;
        }
    } while (next_permutation(permutation + 1, permutation + n));
    
    cout << cases << endl;
    
}
