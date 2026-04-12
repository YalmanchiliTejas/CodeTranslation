#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <locale>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);

    int m;
    cin >> m;
    int h[m];
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }

    int max = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (max <= h[i]) {
            ans++;
            max = h[i];
            // cout << h[i] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
