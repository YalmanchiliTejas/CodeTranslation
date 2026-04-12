//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 8;

int n, answer = 0, v[1 + MAXN];
bool edge[1 + MAXN][1 + MAXN], seen[1 + MAXN];

void Backtracking(int x) {
    if (x == n + 1) {
        answer++;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!seen[i] && edge[v[x - 1]][i]) {
            v[x] = i;
            seen[i] = true;
            Backtracking(x + 1);
            seen[i] = false;
        }
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a][b] = edge[b][a] = true;
    }
    v[1] = 1;
    seen[1] = 1;
    Backtracking(2);
    cout << answer << "\n";
    return 0;
}
