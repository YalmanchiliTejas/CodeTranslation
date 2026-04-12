#include<bits/stdc++.h>
using namespace std;

#define LL long long
int g[10][10], ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, x, y; cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        g[x][y]++, ++g[y][x];
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i + 1;

    do {
        bool ok = 1;
        for(int i = 1; i < n; i++) if(!g[v[i-1]][v[i]]) ok = 0;
        ans += ok;
    }
    while(next_permutation(v.begin() + 1, v.end()));

    cout << ans;
}