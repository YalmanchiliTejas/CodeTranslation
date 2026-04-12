#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> g(N, vector<bool>(N, false));
    REP(_, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a][b] = true;
        g[b][a] = true;
    }

    int result = 0;
    vector<int> p(N);
    REP(i, N) p[i] = i;
    do {
        bool flag = true;
        REP(i, N - 1) {
            if (!g[p[i]][p[i + 1]]) {
                flag = false;
                break;
            }
        }
        result += flag;
    } while (next_permutation(p.begin() + 1, p.end()));
    cout << result << endl;

    return 0;
}