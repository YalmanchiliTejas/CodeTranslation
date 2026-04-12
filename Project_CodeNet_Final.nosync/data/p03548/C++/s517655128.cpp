#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans = z;
    int cnt = 0;
    while (true) {
        ans += (y + z);
        if (ans <= x)
            ++cnt;
        else
            break;
    }
    cout << cnt << endl;

    return 0;
}
