#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[28], b[28];
int perm[8];
int ans = 0;

void permutation(int n) {
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    do {
        if (perm[0] != 0) continue;
        bool mitasu;
        for (int i = 0; i < n-1; i++) {
            mitasu = false;
            for (int j = 0; j < M; j++) {
                if ((perm[i] + 1 == a[j] && perm[i+1] + 1 == b[j]) ||
                    (perm[i] + 1 == b[j] && perm[i+1] + 1 == a[j])) {
                        mitasu = true;
                }
            }
            if (!mitasu) break;
        }
        ans += mitasu;
    } while (next_permutation(perm, perm + n));
    return ;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> a[i] >> b[i];
    permutation(N);
    cout << ans << endl;
    return 0;
}