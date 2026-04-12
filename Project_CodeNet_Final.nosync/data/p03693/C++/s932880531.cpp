#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int r,g,b;
    cin >> r >> g >> b;
    int rhandred = r * 100;
    int gten = g * 10;
    int res = rhandred + gten + b;
    if(res % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}