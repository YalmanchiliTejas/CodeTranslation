#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int x = 800 * n, y = 200 * (n / 15);
    cout << x - y << endl; 

    return 0;
}
