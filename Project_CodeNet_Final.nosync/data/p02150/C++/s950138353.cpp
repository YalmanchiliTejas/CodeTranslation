#include <iostream>
#define MOD 1000000007

using namespace std;
int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long diminish = a - b;
    if (x < a) {
        cout << x%MOD << endl;
        return 0;
    }
    long long trade = (x-a) / diminish + 1;
    trade %= MOD;
    b %= MOD;
    x %= MOD;
    cout << (x + ((trade * b) % MOD)) % MOD << endl;
    return 0;
}
