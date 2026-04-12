#include <iostream>
#define ll long long

using namespace std;

ll thick[55];
ll patty[55];

ll dfs(int n, ll x) {
    if (n == 0) {
        return (x <= 0) ? 0 : 1;
    }
    else if (x <= thick[n - 1] + 1) {
        return dfs(n - 1, x - 1);
    }
    else if (x <= thick[n]) {
        return 1 + patty[n - 1] + dfs(n - 1, x - 2 - thick[n - 1]);
    }
    else {
        return patty[n];
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    thick[0] = 1;
    patty[0] = 1;

    for (int i = 1; i < n + 1; i++) {
        thick[i] = 2 * thick[i - 1] + 3;
        patty[i] = 2 * patty[i - 1] + 1;
    }

    cout << dfs(n, x) << endl;
}