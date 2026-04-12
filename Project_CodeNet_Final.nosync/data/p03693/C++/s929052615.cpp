#include <iostream>

using namespace std;

int main()
{

    int r = 0, g = 0, b = 0;
    cin >> r >> g >> b;

    int com = 100 * r + 10 * g + b;
    if (com % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}