#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
typedef pair <int, int> pii;
typedef long long cc;
const int N = 200005, oo = 1000 * 1000 * 1000;
int a[N], n;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int pos = n;
    while (pos > 0) {
        cout << a[pos] << " ";
        pos -= 2;
    }
    if (n % 2 == 0) pos = 1; else pos = 2;
    while (pos <= n) {
        cout << a[pos] << " ";
        pos += 2;
    }
    return 0;
}
