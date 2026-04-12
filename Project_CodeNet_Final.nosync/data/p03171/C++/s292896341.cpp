#include <bits/stdc++.h>

using namespace std;

#define maxN 3010

typedef long long ll;

int n;
ll as[maxN];
ll sum = 0;

ll cache[maxN][maxN];

ll rec(int i, int j, ll remainingSum) {
    if (i == j) return as[i];
    if (cache[i][j] != -1) return cache[i][j];
    return cache[i][j] =
                   max(remainingSum - rec(i + 1, j, remainingSum - as[i]),
                       remainingSum - rec(i, j - 1, remainingSum - as[j]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        sum += as[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cache[i][j] = -1;
        }
    }
    ll X = rec(0, n - 1, sum);
    cout << X - (sum - X) << endl;
    return 0;
}