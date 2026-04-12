#include <iostream>
#include <string>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    bool ret = (100*r + 10*g + b) %4 == 0;
    cout << (ret ? "YES" : "NO") << endl;
    return 0;
}