#include <iostream>
#include <vector>
using namespace std;
int n, m, p[10], res;
vector<int> vec[10];
void dfs (int pos, int mask) {
    if (pos == n) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < vec[p[i - 1]].size(); j++) {
                if (vec[p[i - 1]][j] == p[i]) ans++;
            }
        }
        if (ans == n - 1) res++;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (mask & (1 << i)) {
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
        vec[a - 1].push_back(b - 1);
        vec[b - 1].push_back(a - 1);
    }
    dfs(1, (1 << n) - 2);
    cout << res << endl;
}
