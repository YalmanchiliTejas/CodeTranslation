#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < i; j++) {
            if(h[i] < h[j]) {
                flag = false;
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}