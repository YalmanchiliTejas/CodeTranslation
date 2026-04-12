#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

void f(int index, vector<int>& visited, const vector<vector<int>>& v, int & res, int c) {
    if (c == visited.size() - 1) {
        res++;
        return;
    }
    for (int i = 1; i <= visited.size(); i++) {
        if (visited[i] == 0 && v[index][i] == 1) {
            visited[i] = 1;
            f(i, visited, v, res, c + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    int res = 0;
    vector<int> visited(n + 1, 0);
        visited[1] = 1;
        f(1, visited, v, res, 1);
        visited[1] = 0;
    
    cout << res << endl;
}
