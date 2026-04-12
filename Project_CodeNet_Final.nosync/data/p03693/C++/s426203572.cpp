#include <iostream>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int tmp = r * 100 + g * 10 + b;
    string ans = (tmp % 4 == 0) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
