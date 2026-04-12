#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main(void) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A) cin >> a;

    long long result = 0, sum = 0;
    for (int i = n - 1; i > 0; i--) {
        sum = (sum + A[i]) % MOD;
        result = (result + A[i - 1] * sum) % MOD;
    }
    cout << result << endl;

    return 0;
}
