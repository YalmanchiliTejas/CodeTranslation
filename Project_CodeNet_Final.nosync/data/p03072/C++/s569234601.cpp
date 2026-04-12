
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, ans = 0, x, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= m) {
            ans++;
        }
        m = max(x, m);
    }

    cout << ans;
    return 0;
}

