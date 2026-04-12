#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int y = N / 15;
    cout << N * 800 - 200 * y << endl;
    return 0;
}