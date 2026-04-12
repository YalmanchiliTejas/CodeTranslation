#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    auto Y = X;
    sort(begin(X), end(X));
    vector<int> ord(N);
    for(int i = 0; i < N; ++i) {
        ord[i] = lower_bound(begin(X), end(X), Y[i]) - begin(X);
    }
    for(int i = 0; i < N; ++i) {
        if(ord[i] < N / 2) {
            cout << X[N / 2] << endl;
        } else {
            cout << X[N / 2 - 1] << endl;
        }
    }
}