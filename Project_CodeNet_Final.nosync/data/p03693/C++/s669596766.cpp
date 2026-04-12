#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if ((a * 100 + b * 10 + c) %  4 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
