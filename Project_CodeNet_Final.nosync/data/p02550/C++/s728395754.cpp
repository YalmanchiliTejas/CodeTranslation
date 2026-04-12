#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

int main() {
    long n,x,m;
    cin >> n >> x >> m;

    int k = log2(n) + 1;
    vector tb(k+1, vector(m, -1LL));
    vector sum(k+1, vector(m, 0LL));
    unordered_map<long,bool> mp;

    for (long i=0; i<m; i++) tb[0][i] = i*i % m;
    iota(sum[0].begin(), sum[0].end(), 0);

    for (int i=0; i<k; i++) {
        for (int j=0; j<m; j++) {
            if (tb[i][j] == -1) tb[i+1][j] = -1;
            else {
                sum[i+1][j] = sum[i][j] + sum[i][tb[i][j]];
                tb[i+1][j] = tb[i][tb[i][j]];
            }
        }
    }

    long ans = 0;
    for (int i=0; i<=k; i++) {
        if ((n>>i) & 1) {
            ans += sum[i][x];
            x = tb[i][x];
        }
    }

    cout << ans << endl;
}