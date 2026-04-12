#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int count = 1;
    while (1) {
        if (count*y + (count+1)*z > x) break;
        count++;
    }

    cout << --count << endl;
}