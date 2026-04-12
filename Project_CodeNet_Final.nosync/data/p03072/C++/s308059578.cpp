#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    int ans = 1;
    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (h[j] > h[i]) {
                flag = false;
                break;
            }
        }
        if (flag)
            ans ++;
    }

    cout << ans << endl;
}