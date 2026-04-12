#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    ll z = 0;
    cin >> n >> k;
    if (!k) {
        cout << (ll)n * n;
        return 0;
    }
    for (int i = k; i <= n; i++) {
        int y = -1;
        for (int j = 0; j * i <= n; j++) {
            if (j * i + k <= n) y += k;
            else y += n - j * i + 1;
        }
        z += n - y;
    }
    cout << z;
}
