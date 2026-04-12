#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int total;
    total = 800 * n;

    int bonus;
    bonus = n / 15;

    cout << total - 200 * bonus << endl;
}