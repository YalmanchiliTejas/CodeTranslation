#include <bits/stdc++.h>
using namespace std;

const int MD = 998244353;
const int M = 3030;
int n, s;
vector<int> a;

int main() {
    while (scanf("%d %d", &n, &s) == 2) {
        a.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> sum(M, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            sum[0] = i + 1;
            if (s - x >= 0) {
                //cerr << "i: " << i << ", res: " << res << "->";
                res = (res + 1ll * sum[s - x] * (n - i) % MD) % MD;
                //cerr << res << "\n";
            }

            vector<int> nSum = sum;
            for (int i = 0; i < M; i++) {
                if (i + x >= M) continue;
                nSum[i + x] = (nSum[i + x] + sum[i]) % MD;
            }
            sum = nSum;
        }
        printf("%d\n", res);
    }
    return 0;
}
