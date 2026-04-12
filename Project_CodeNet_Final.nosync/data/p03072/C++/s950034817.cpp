#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int ans = 1;
    cin >> n;
    int hi[n];
    for(int i = 0; i < n; i++)
        cin >> hi[i];
    int max = hi[0];
    for(int i = 1; i < n; i++) {
        if(hi[i] >= max) {
            ans++;
            max = hi[i];
        }
    }
    cout << ans << endl;
}