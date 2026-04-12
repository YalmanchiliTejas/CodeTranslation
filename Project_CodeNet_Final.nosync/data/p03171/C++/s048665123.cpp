#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#define f cin
#define NMAX 3010
using namespace std;

//ifstream f("date.in");

long long int v[NMAX], dp[NMAX][NMAX][2];
long long int dist_arr[NMAX], n;

long long int calc_dist(long long int x, long long int y) {
    return (dist_arr[y] - dist_arr[x] + v[x]);
}

int main() {

    f >> n;
    for (int i = 0; i < n; ++i) {
        f >> v[i];
        if (i == 0) {
            dist_arr[i] = v[0];
        } else {
            dist_arr[i] = dist_arr[i - 1] + v[i];
        }
    }

    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            if (l == 0) {
                dp[i][i + l][0] = v[i];
                dp[i][i + l][1] = v[i];
            } else {
                dp[i][i + l][0] = max(v[i] + calc_dist(i + 1, i + l) - dp[i + 1][i + l][1],
                                      v[i + l] + calc_dist(i, i + l - 1) - dp[i][i + l - 1][1]);
                dp[i][i + l][1] = max(v[i] + calc_dist(i + 1, i + l) - dp[i + 1][i + l][0],
                                      v[i + l] + calc_dist(i, i + l - 1) - dp[i][i + l - 1][0]);
            }
        }
    }

    cout << 2 * dp[0][n - 1][0] - dist_arr[n - 1];

    return 0;
}
