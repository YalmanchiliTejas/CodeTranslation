#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

int factorial(int n) {
    int f = 1;
    REP(i, 1, n) f *= i;
    return f;
}

int main() {
    int N, M; cin >> N >> M;
    int G[N][N] = {0};
    REP(i, 0, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    vector<int> order(N);
    REP(i, 0, N) order[i] = i;

    int ans = 0;
    REP(i, 0, factorial(N)) {
        bool ok = true;
        REP(j, 0, N - 1) {
            if (G[order[j]][order[j + 1]] != 1) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
        next_permutation(order.begin(), order.end());
    }

    cout << ans << endl;
    return 0;
}