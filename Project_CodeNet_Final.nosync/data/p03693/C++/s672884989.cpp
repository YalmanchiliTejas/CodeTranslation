#include <iostream>
using namespace std;

int main()
{
    int r, g, b;
    int a;
    cin >> r >> g >> b;
    a = g * 10 + b;
    if (a % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}