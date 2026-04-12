#include <bits/stdc++.h>

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N, X, M;
    cin >> N >> X >> M;

    vector<ll> A;
    A.push_back(X);
    ll index = -1;
    ll tmp;
    for (ll i = 1; i < N; i++) {
        tmp = (A[i - 1] * A[i - 1]) % M;
        if (find(A.begin(), A.end(), tmp) != A.end()) {
            // cout << tmp << " " << A[i - 1] << " " << A[i - 1] * A[i - 1] % M
            // << endl;
            index = find(A.begin(), A.end(), tmp) - A.begin();
            break;
        }
        A.push_back(tmp);
    }

    // for (int i = 0; i < A.size(); i++) {
    // cout << i << " " << A[i] << endl;
    // }
    // cout << index << " " << A[index] << endl;

    if (index == -1) {
        ll output = 0;
        for (ll i = 0; i < N; i++) {
            output += A[i];
        }
        cout << output << endl;
        return 0;
    }

    ll repeat = 0;
    for (ll i = index; i < A.size(); i++) {
        repeat += A[i];
    }
    ll output = 0;
    for (ll i = 0; i < index; i++) {
        output += A[i];
    }
    N -= index;
    ll tmp2 = A.size() - index;
    ll m, n;
    if (tmp2 == 0) {
        m = N;
        n = 0;
    } else {
        m = N / tmp2;
        n = N % tmp2;
    }
    // cout << "re" << repeat << endl;
    output += m * repeat;
    for (ll i = index; i < index + n; i++) {
        output += A[i];
    }

    cout << output << endl;

    return 0;
}
