#include <iostream>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C;
    cin >> A >> B >> C;
    if ((100 * A + 10 * B + C) % 4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}