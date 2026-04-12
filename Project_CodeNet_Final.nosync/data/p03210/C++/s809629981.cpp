#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    int X;
    cin >> X;

    switch (X) {
        case 3:
        case 5:
        case 7:
            cout << "YES";
            break;
        default:
            cout << "NO";
    }

    return 0;
}
