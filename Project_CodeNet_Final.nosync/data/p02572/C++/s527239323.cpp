#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    long long mod = 1000000007;

    long long sum = 0;
    long long right = A.at(N-1) % mod;
    for(long long i = N - 2; i >= 0; i--) {
        long long left = A.at(i) % mod;
        sum += (left * right) % mod;
        right += left;
        right = right % mod;
    }

    cout << sum % mod << endl;
}
