#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<int> X(N), v;
    for (int i = 0; i < N; i++) cin >> X[i];
    v = X;
    sort(v.begin(), v.end());
    int a = v[N/2-1], b = v[N/2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= a) {
            cout << b << endl;
        }
        else {
            cout << a << endl;
        }
    }
}