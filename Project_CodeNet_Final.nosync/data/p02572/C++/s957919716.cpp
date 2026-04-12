#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    int64_t tmp = 0;
    int64_t sum = 0;
    int64_t MOD = 1000000007;

    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for(int i = N-1; i >= 1; i--) {
        tmp += A.at(i);
        sum += A.at(i-1) * tmp;
        tmp %= MOD;
        sum %= MOD;
    }
    
    cout << sum << endl;

    return 0;
    
}