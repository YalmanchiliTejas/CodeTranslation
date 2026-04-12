#include <iostream>
using namespace std;

int main()
{
    int X;
    int Y;
    int Z;

    cin >> X;
    cin >> Y;
    cin >> Z;

    X -= Z;

    cout << (int)(X / (Y + Z)) << endl;

    return 0;
}