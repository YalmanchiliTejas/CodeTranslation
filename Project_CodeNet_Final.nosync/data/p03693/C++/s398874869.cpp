#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
typedef long long ll;

int main() {

    int r, g, b; cin >> r >> g >> b;

    int t = 100 * r + 10 * g + b;

    if (t % 4 == 0) {
        puts("YES");
    } else {
        puts("NO");
    }
}