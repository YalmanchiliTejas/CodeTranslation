#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> b(n);
    int j = n / 2, k = n % 2 == 0 ? -1 : 1;
    for (int i = 0; i < n; i++) {
        cin >> b[j];
        j += k;
        k *= -1;
        if (k < 0) k--; else k++;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}