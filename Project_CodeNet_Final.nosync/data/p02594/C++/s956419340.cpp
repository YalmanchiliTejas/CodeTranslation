#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;
    if (X >= 30)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}