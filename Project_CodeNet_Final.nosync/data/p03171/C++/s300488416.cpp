#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<long long>> dp(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        cin >> dp.at(i).at(i);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j + i < N; j++) {
            dp.at(j).at(j + i) = max(dp.at(j).at(j) - dp.at(j + 1).at(j + i), dp.at(j + i).at(j + i) - dp.at(j).at(j + i - 1));
        }
    }
    cout << dp.at(0).at(N - 1) << endl;
}