#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;

int main(void)
{
    int32_t X;
    cin >> X;

    if (X == 3 || X == 5 || X == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

