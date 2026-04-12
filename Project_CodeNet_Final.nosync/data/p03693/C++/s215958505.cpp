#include <iostream>

using namespace std;

int main()
{
    string r, g, b;
    cin >> r >> g >> b;
    int a = stoi(r + g + b);

    if (a % 4 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
