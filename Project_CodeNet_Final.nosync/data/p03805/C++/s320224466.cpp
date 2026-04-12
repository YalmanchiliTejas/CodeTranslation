#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define MAX_N 8
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int G[MAX_N][MAX_N];
int N;

int dfs(int flags, int now) {
    if (flags == (1 << (N-1)) - 1) return 1;
    int score = 0;
    for (int i = 1; i < N; i++) {
        score += ((flags & (1 << (i-1))) == 0 && G[now][i] > 0) ? dfs(flags + (1 << (i-1)), i) : 0;
    }
    return score;
}

int main() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    cout << dfs(0, 0) << endl;

    return 0;
}