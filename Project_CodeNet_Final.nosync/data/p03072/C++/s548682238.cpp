#include<iostream>
using namespace std;

int main() {
    int n, h[30];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 1, max_h = h[0];
    for (int i = 1; i < n; i++) {
        if (h[i] >= max_h) {
            ans++;
            max_h = h[i];
        }
    }
    
    cout << ans << endl;

}