#include <iostream>
using namespace std;
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    if ((100 * r + 10 * g + b) % 4 == 0)
        puts("YES");
    else
        puts("NO");
}