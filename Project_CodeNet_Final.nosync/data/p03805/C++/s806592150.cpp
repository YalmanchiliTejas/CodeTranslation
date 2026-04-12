#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <map>
#include <set>

using ll = long long;
using namespace std;

int N, M;
vector<vector<int>> mat;

bool isend(vector<bool> visited) {
    for (int i = 0; i < N; i++) {
        if (!visited[i])return false;
    }
    return true;
}

//現在の頂点
int dfs(int v, vector<bool> visited) {
    //すべての頂点訪問済み
    if (isend(visited)) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i])continue;
        //辺が存在する
        if (mat[v][i] == 1) {
            visited[i] = true;
            ret += dfs(i, visited);
            visited[i] = false;
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    mat = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    vector<bool>visited(N);
    visited[0] = true;
    cout << dfs(0, visited)
        << endl;
    return 0;
}
