#include <iostream>

using namespace std;

int main(void)
{
    int N, x, y;

    cin >> N;

    x = N*800;
    y = 200*(N/15);

    cout << x-y << endl;

    return 0;
}