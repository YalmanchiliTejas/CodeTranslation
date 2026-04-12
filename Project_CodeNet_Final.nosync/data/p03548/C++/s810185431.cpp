#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int ans = (x - z) / (y + z);

    cout << ans << endl;

    return 0;
}
