#include <iostream>

using namespace std;

int main()
{
    int X,Y,Z;
    cin >> X >> Y >> Z;
    /*cout << X % (Y + Z) << '\n';
    cout << X % (Y + Z) % Z << '\n';*/
    if((X % (Y+Z)) % Z == 0 && (X % (Y+Z)))
        cout << (X / (Y + Z));
    else
        cout << (X / (Y + Z)) - 1;
    return 0;
}
