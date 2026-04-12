#include <math.h>

#include <iostream>
using namespace std;

const int N_MX = 200000;
const long long int MOD = pow(10, 9) + 7;
int n;
long long int a[N_MX];
long long int ans;
long long int sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        sum -= a[i];
        ans = (ans + (a[i] * (sum % MOD)) % MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}