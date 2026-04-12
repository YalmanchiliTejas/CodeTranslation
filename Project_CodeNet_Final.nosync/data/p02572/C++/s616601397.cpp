#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long int> s(n + 1);
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    long long int result = 0;
    long long int temp = 0;

    for (int i = 0; i < n; i++) {
        temp = (s[n] - s[i + 1]) % MOD;
        temp = (a[i] * temp) % MOD;
        result = (temp + result) % MOD;
    }

    cout << result << endl;

    return 0;
}