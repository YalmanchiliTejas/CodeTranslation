//
// Created by kuroneko on 2019-07-06.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

typedef long long ll;
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N), max_H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    for (int i = 0; i < N; i++) {
        max_H[i+1] = max(max_H[i], H[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (max_H[i] <= H[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}