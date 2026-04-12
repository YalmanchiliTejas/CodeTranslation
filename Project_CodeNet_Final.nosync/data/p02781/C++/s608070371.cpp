#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solver(string N, int K) {
    int n = N.length();
    if (N[0] == '0') {
        if (n == 1) {
            return 0;
        } else {
            return solver(N.substr(1), K);
        }
    } else if (K == 1) {
        return N[0] - '0' + (n-1) * 9;
    } else if(K == 2) {
        if (n == 1) {
            return 0;
        } else if (n == 2) {
            return ((N[0] - '0') - 1) * 9 + N[1] - '0';
        } else {
            return 9 * 9 * (n-1) * (n-2) / 2 + (N[0] - '0' - 1) * 9 * (n-1) + solver(N.substr(1), 1);
        }
    } else if (K == 3) {
        if (n <= 2) {
            return 0;
        } else if (n == 3) {
            if (N[1] == '0') {
                return ((N[0] - '0') - 1) * 9 * 9;
            } else {
                return ((N[0] - '0') - 1) * 9 * 9 + ((N[1] - '0') - 1) * 9 + N[2] - '0';
            }
        } else {
            return 9 * 9 * 9 * (n-1) * (n-2) * (n-3) / 6 + max(0, N[0] - '0' - 1) * 9 * 9 * (n-1) * (n-2) / 2 + solver(N.substr(1), 2);
        }
    }
    return 0;
}

int main() {
    string N; cin >> N;
    int K; cin >> K;
    cout << solver(N, K) << endl;
    return 0;
}
