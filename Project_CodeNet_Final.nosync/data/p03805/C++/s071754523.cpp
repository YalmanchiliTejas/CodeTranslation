#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int table[10][10] = {};
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        table[a][b] = 1;
        table[b][a] = 1;
    }

    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i+1;
    }
    int ans = 0;
    do {
        bool flag = true;
        for (int i = 0; i < n-1; ++i) {
            if (table[path[i]][path[i + 1]] == 0) flag = false;
        }
        if (flag) ans++;
    } while(next_permutation(path.begin()+1, path.end()));

    cout << ans << endl;
}