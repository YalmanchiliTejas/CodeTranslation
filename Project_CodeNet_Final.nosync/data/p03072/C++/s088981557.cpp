#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int max = h[0];

    for (int i = 1; i < n; i++) {
        max = h[i-1] - max > 0 ? h[i-1]: max;
        
        if (h[i] >= max) {
            ans++;
        }
    }
    cout << ans << endl;
}
