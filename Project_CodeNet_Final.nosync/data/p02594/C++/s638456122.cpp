#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

void a_aircon(void) {
    int x;
    cin >> x;

    if (x >= 30) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main()
{
    a_aircon();

    return 0;
}