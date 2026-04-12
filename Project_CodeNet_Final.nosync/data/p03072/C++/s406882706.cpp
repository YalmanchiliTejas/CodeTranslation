#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    int h[22];
    int max = 0;
    int ans = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (max <= h[i]) {
            max = h[i];
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}