#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;

void add(int& A, int B) {
    A += B;
    while (A >= mod) {
        A -= mod;
    }
}

int sub(int A, int B) {
    int res = A - B;
    while (res < 0) {
        res += mod;
    }
    return res;
}

int mult(int A, int B) {
    return (long long) A * B % mod;
}

int n;
int a[N];
int pref[N];

int get(int l, int r) {
    if (l) {
        return sub(pref[r], pref[l - 1]);
    }
    return pref[r];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i] = a[i];
        if (i) {
            add(pref[i], pref[i - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = get(i + 1, n - 1);
        add(ans, mult(a[i], sum));
    }
    cout << ans << endl;
    return 0;
}
