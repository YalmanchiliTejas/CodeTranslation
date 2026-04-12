#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int ans = 0;

void look(vector <vector <int> > gr, vector <int> visited, int cur, int n) {
    bool flag = true;
    visited[cur] = 1;
    for (int k : gr[cur]) {
        if (!visited[k]) {
            look(gr, visited, k, n);
            flag = false;
        }
    }
    if (flag) {
        for (int i=1; i < n + 1; ++i) {
            if (visited[i] == 0) flag = false;
        }
        if (flag) ++ans;
    }
    visited[cur] = 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > gr;
    gr = vector <vector <int>> (n+1);
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        gr[ai].push_back(bi);
        gr[bi].push_back(ai);
    }
    vector <int> visited(n+1, 0);
    look(gr, visited, 1, n);
    cout << ans;



}

int main() {

    solve();
    return 0;
}
