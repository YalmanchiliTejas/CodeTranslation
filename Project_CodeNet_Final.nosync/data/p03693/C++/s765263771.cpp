#include <iostream>
using namespace std;

int main(void)
{
    int r, g, b;
    cin >> r >> g >> b;
    int temp = 10 * g + b;
    if (temp % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}