#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> b(n * 2);

    int j = n, d = 1, s = 1, m = n;
    if (n % 2 == 0) s *= -1;

    for (int i = 0; i < n; i++) {
        m = min(m, j);
        cin >> b[j];

        j += s * d;
        d++;
        s *= -1;
    }

    for (int i = 0; i < n; i++) {
        cout << b[m + i] << " \n"[i == n - 1];
    }

    return 0;
}