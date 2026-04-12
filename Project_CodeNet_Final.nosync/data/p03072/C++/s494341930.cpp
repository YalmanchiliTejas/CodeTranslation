#include <iostream>

using namespace std;

int main() {
    int n, *H;
    cin >> n;
    H = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> H[i];
    int ans = 1;
    int i = 0;
    for (i = 1; i < n; i++) {
        bool can = true;
        for (int j = 0; j < i; j++) {
            if (H[j] > H[i])
                can = false;
        }
        if (can)
            ans++;
    }
    cout << ans << endl;
    return 0;
}