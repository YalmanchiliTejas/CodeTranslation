#include <iostream>
using namespace std;
int f[8][8], n, m, p[10], res;

void dfs(int pos, int mask) {
    if (pos == n) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (f[p[i - 1]][p[i]] == 0) ans++;
        }
        if (ans == 0) res++;
        return;
    }
    for (int i = 1; i < n; i++) {
        if(mask & (1 << i)) {
            p[pos] = i;
            dfs(pos + 1, mask ^ (1 << i));
        }
    }
}

int main(void){
    // Your code here!
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        f[a - 1][b - 1] = 1;
        f[b - 1][a - 1] = 1;
    }
    dfs(1, (1 << n) - 2);
    cout << res << endl;
}
