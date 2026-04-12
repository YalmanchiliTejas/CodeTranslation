#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long double r1,r2,r3;
    cin >> r1 >> r2;
    r3=pow((pow(r1,-1)+pow(r2,-1)),-1);
    cout <<fixed<<setprecision(10)<<r3;
    return 0;
}