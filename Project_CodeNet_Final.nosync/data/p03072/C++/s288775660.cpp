#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int ans = 0;
    int curMax = 1;
    for (int i = 0; i < n; i++) {
        if (h[i] >= curMax) {
            ans++;
            curMax = h[i];
        }
    }

    cout << ans;
    
    return 0;
}