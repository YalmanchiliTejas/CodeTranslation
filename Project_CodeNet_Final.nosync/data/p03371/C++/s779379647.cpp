//#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
using namespace std;
// using ll = long long int;

void inv(vector<int>& v) {
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}
void inv(vector<int>& v, int length) {
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 2 * 5000 * pow(10, 5);
    int z = max(x, y);
    for (int i = 0; i <= z; i++) {
        int yen = 2 * c * i + a * max(0, x - i) + b * max(0, y - i);
        ans = min(ans, yen);
    }
    cout << ans << endl;
    return 0;
}
