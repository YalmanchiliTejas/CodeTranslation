#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = 1 << n;
    string S;
    cin >> S;
    vector<int> P(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &P[i]);

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    auto dfs = [&](int i, int k, auto self) -> int {
        if (k == 0)
            return i;
        if (memo[k][i] >= 0)
            return memo[k][i];
        int l = self(i, k - 1, self);
        int r = self((i + (1 << (k - 1))) & (m - 1), k - 1, self);

        if (P[l] > P[r])
            swap(l, r);

        return memo[k][i] = S[P[r] - P[l] - 1] == '1' ? r : l;
    };

    for (int i = 0; i < m; i++)
        printf("%d\n", P[dfs(i, n, dfs)]);
}
