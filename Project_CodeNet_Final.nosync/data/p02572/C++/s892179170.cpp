#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    vector<long long>A(N), B(N); 
    for (long long i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    B.at(0) = A.at(0);
    for (long long i = 1; i < N; i++) {
        B.at(i) = B.at(i - 1) + A.at(i);
    }
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        ans += A.at(i) * ((B.at(N - 1) - B.at(i)) % 1000000007);
        ans %= 1000000007;
    }
    cout << ans % 1000000007 << endl;
}