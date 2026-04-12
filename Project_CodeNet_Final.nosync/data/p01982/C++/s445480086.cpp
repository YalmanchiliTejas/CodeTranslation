#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int l, int r) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int now_a = l; now_a <= r; now_a++) {
        bool is_ok = true;
        bool is_continue = true;
        for (int i = 0; i < n; i++) {
            if (now_a % a[i] == 0 && i % 2) {
                is_ok = false;
                break;
            }
            else if (now_a % a[i] == 0 && i % 2 == 0) {
                is_continue = false;
                break;
            }
        }
        if (!is_ok) continue;
        if (!is_continue) {
            ans++;
            continue;
        }
        if (n % 2 == 0) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, L, R;
    while (true) {
        cin >> N >> L >> R;
        if (N == 0 && L == 0 && R == 0) break;
        solve(N, L, R);
    }
    return 0;
}
