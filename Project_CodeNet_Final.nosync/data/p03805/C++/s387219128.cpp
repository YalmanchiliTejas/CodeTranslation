#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 8, INDEX = 1;

int n, m, ans = 0;

bool isEdge[MAX_N + INDEX][MAX_N + INDEX];

int per[MAX_N + INDEX];

bool isUsed[MAX_N + INDEX];

bool isGood() {
    for (int i = 1; i < n; i++) {
        if (!isEdge[per[i]][per[i + 1]]) {
            return false;
        }
    }

    return true;
}

void getPermutation(int deep) {
    if (deep == n) {
        if (isGood()) {
            ans++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            per[deep + 1] = i;

            isUsed[i] = true;

            getPermutation(deep + 1);

            isUsed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        isEdge[a][b] = true;
        isEdge[b][a] = true;
    }

    per[1] = 1;

    isUsed[1] = true;

    getPermutation(1);

    cout << ans << endl;

    return 0;
}
