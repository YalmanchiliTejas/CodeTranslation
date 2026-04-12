#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int height[n];
    int temp, ans;

    ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int k = 0; k < i; k++) {
            if (height[k] > temp) temp = height[k];
        }
        if (temp <= height[i]) ans += 1;
    }

    cout << ans << endl;

    return 0;
}
