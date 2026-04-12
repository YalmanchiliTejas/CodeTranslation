#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--, i--) cout << a[i] << ' ';
    if (n % 2) for (int i = 2; i <= n; i++, i++) cout << a[i] << ' ';
    else for (int i = 1; i <= n; i++, i++) cout << a[i] << ' ';
}
