#include <iostream>
using namespace std;

const long long MOD = 1000000007;
int main() {
    long long a, b, x;
    cin >> a >> b >> x;

    long long N = max(0LL, (x - b) / (a - b));
    x %= MOD;
    N %= MOD;
    b %= MOD;
    cout << (x + N * b) % MOD << endl;
}

