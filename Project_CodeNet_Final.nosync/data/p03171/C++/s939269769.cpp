#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;
typedef vector<long long int> vi;
typedef vector<vi> vvi;

int main() {
    int n;
    cin >> n;
    long long int p[n], cSum[n+1];
    long long int sum = 0;
    cSum[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
        cSum[i+1] = cSum[i] + p[i];
    }

    vvi win(n, vi(n));
    for (int i = 0; i < n; i++) {
        win[i][i] = p[i];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            win[i][j] = max(cSum[j] - cSum[i] - win[i][j-1] + p[j], cSum[j+1] - cSum[i+1] - win[i+1][j] + p[i]);
        }
    }
    cout << (2 * win[0][n-1] - sum) << endl;

    return 0;
}

