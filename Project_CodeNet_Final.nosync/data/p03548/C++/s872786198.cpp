#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int already_space = z, count = 0;

    for (int i = 0; already_space < x; i++)
    {
        already_space += y + z;
        count++;
    }
    if (already_space > x) count--;
    cout << count << endl;
    return (0);
}