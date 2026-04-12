#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N;
    cin >> N;
    
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int64_t result = 0;
    int64_t n = 1000000000 + 7;

    int sum = 0;

    for (int i = N - 2; i >= 0; i--) {
        sum += a[i + 1];
        sum %= n;
        result += a[i] * sum;
        result %= n;
    }

    cout << result << endl;
}