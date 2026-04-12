#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <list>
using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X -= Z;
    cout << X / (Y + Z) << endl;
    return 0;
}