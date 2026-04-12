#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int x[200000], y[200000];
int idx[200000];

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
    }
    int ans;
    int R_max, B_max, R_min, B_min;
    R_max = B_max = 0, R_min = B_min = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        R_max = max(R_max, x[i]), R_min = min(R_min, x[i]);
        B_max = max(B_max, y[i]), B_min = min(B_min, y[i]);
    }
    ans = (R_max - R_min) * (B_max - B_min);

    R_max = B_max = 0, R_min = B_min = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        idx[i] = i;
        R_max = max(R_max, y[i]), R_min = min(R_min, x[i]);
        B_max = max(B_max, x[i]);
    }

    sort(idx, idx + N, [](int l, int r) { return y[l] < y[r]; });
    stable_sort(idx, idx + N, [](int l, int r) { return x[l] < x[r]; });
    int y_min = LLONG_MAX;
    for (int i = 0; i < N - 1; i++) {
        B_max = max(B_max, y[idx[i]]);
        y_min = min(y_min, y[idx[i]]);
        B_min = min(y_min, x[idx[i + 1]]);
        ans = min(ans, (R_max - R_min) * (B_max - B_min));
    }

    cout << ans << endl;
}