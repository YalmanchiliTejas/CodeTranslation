#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int j = i; j >= 0; j--) {
            if (a[i] < a[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            ans++;
    }
    cout << ans+1 << endl;


    return 0;
}