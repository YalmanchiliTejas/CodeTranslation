#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    int h[10010] = {};
    int ans = 0;
    bool flg = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ans++;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (h[j] > h[i]) {
                flg = 0;
            }
        }
        if (flg && h[i-1] <= h[i]) {
            ans++;
        }
        flg = true;
    }

    cout << ans << endl;
}
