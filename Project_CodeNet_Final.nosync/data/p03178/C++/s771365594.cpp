#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long mod = 1e9 + 7;

int d, n, i, j, k;

vector<int> v;
vector< vector<long long> > x[2];
string s;

int main() {
    cin >> s >> d;
    n = s.size();
    v.resize(n);
    for (i = 0; i < n; i++) {
        v[i] = s[i] - '0';
    }
    x[0].resize(n, vector<long long>(d, 0));
    x[1].resize(n, vector<long long>(d, 0));
    for (i = 0; i < v[0]; ++i) {
        ++x[0][0][i % d];
    }
    ++x[1][0][v[0] % d];
    for (i = 1; i < n; ++i) {
        for (j = 0; j < d; ++j) {
            for (k = 0; k < 10; ++k) {
                x[0][i][(j + k) % d] += x[0][i - 1][j];
                x[0][i][(j + k) % d] %= mod;
            }
            for (k = 0; k < v[i]; ++k) {
                x[0][i][(j + k)%d] += x[1][i - 1][j];
                x[0][i][(k + k)%d] %= mod;
            }
            x[1][i][(j + v[i]) % d] += x[1][i - 1][j];
            x[1][i][(j + v[i]) % d] %= mod;
        }
    }
    cout << (x[0][n - 1][0] + x[1][n - 1][0] + mod - 1) % mod << "\n";
    return 0;
}
