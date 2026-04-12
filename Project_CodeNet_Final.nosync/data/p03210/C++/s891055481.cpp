#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    if (x == 7 || x == 5 || x == 3)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
