#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int a[50];
int cur[50];

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    while (true) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cur[i] = a[i] / N;
            sum += cur[i];
        }
        if (sum == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            a[i] += sum - cur[i] - cur[i] * N;
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
