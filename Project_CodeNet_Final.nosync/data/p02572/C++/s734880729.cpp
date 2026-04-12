#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long sum = 0, tmp;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        if (i == 0) {
            tmp = A.at(i);
        } else {
            long long k = tmp * A.at(i) % 1000000007;
            sum += k;
            tmp += A.at(i);
            sum %= 1000000007;
            tmp %= 1000000007;
        }
    }
    cout << sum << endl;
}