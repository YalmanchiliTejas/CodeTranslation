#include <iostream>
using namespace std;
int main()
{
    int r, b, g;
    cin >> r >> b >> g;
    cout << ((b*10 + g) % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}