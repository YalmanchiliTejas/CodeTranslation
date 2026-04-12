#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

vector<long long int> fac;

const int mod = 1e9 + 7;

long long int mypow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long int res = mypow(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 1) res = res * a % mod;
    return res;
}

long long int myc(long long int a, long long int b) {
    return fac[a] * mypow(fac[b], mod - 2) % mod * mypow(fac[a - b], mod - 2) % mod;
}

int main() { 
    long long int n, m, k;
    cin >> n >> m >> k;
    fac.push_back(1);
    for (int i = 1; i <= n * m; i++) {
        fac.push_back(fac.back() * i % mod);
    }
    long long int res = 0;
    long long int col_dist = 0, row_dist = 0;
    long long int col_type = 0, row_type = 0;
    for (long long int i = 0; i <= m - 1; i++) {
        col_dist += i * (m - i) % mod;
        col_dist %= mod;
        col_type += m - i;
        col_type %= mod;
    }
    col_type = n * n % mod;
    for (long long int i = 0; i <= n - 1; i++) {
        row_dist += i * (n - i) % mod;
        row_dist %= mod;
        row_type += n - i;
        row_type %= mod;
    }
    row_type = m * m % mod;
    cout << (col_dist * col_type + row_type * row_dist) % mod * myc(m * n - 2, k - 2) % mod << endl;

}


