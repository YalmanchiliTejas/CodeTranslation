#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 1; i <= n; i++)

int main() {
    int N;
    cin >> N;

    int pay = N * 800;
    int a = pay / 800;
    int discount = a / 15;
    int total = 0;

    rep (i, discount) {
        total = i * 200;
    }

    cout << pay - total << endl;

    return 0;
}