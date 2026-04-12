#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
typedef long long ll;
using namespace std;

int n,m;
int c = 0;
bool graph[10][10];
bool visited[10];

void dfs(int y, int x) {
    if (visited[y]) return;
    visited[y] = true;
    bool allv = true;
    for (int i = 0; i < n; ++i) if (!visited[i]) allv = false;
    if (allv) c++;
    for (int i = 0; i < n; ++i) if (graph[y][i]) dfs(i, y);
    visited[y] = false;
    return;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) graph[i][j] == false;
    for (int i = 0; i < n; ++i) visited[i] = false;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }
    
    dfs(0, 0);
    cout << c << std::endl;
    return 0;
}