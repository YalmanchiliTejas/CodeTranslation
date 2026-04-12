#include <iostream>
using namespace std;

int main()
{
    int n;
    int max = 0, ans = 0;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] >= max) {
            max = h[i];
            ans++;
        }
    }
    cout << ans << endl;
    return (0);
}