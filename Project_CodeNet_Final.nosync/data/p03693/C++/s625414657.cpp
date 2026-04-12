#include <iostream>

using namespace std;
int r, g, b;
int num;
int main()
{
    cin >> r >> g >> b;
    num = b + g * 10 + r * 100;
    if(num % 4 == 0)
        cout <<"YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}