#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,x,y;
    cin >> n;
    int t = 0;
    t = n / 15;
    y = 200 * t;
    x = 800 * n;
    cout << x - y << endl;

}
