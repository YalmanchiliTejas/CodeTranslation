#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main(void)
{
    int x, y, z;

    cin >> x >> y >> z;

    int i = 0;
    int t = 0;
    int ans = 0;
    while(t+y+z <= x) {
        if (i % 2 == 0) {
            t += z;
        }
        else {
            t += y;
            ans++;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}