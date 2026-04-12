#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;
vector<int> flags(10);
vector<vector<int>> table(10, vector<int>(10));

int recurse(int num) {

    int flag = 1;
    for (int i = 1; i <= n && flag; i++) flag = flags[i];
    if (flag) return 1;
 
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (table[num][i] && !flags[i]) {
            flags[i] = 1;
            sum += recurse(i);
            flags[i] = 0;
        }
    }

    return sum;
}

int main() {
    cin >> n >> m;
    a.resize(m); b.resize(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++) table[a[i]][b[i]] = table[b[i]][a[i]] = 1;
    flags[1] = 1;
    int ans = recurse(1);
    cout << ans << endl;
    return 0;
}