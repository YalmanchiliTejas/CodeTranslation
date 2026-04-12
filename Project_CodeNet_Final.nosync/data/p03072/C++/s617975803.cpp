#include <iostream>
using namespace std;

int main() {
    int n, h;
    cin >> n;
    int maxh = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        cin >> h;
        if (maxh <= h) ans++;
        maxh = max(maxh, h);
    }
    cout << ans << endl;
}