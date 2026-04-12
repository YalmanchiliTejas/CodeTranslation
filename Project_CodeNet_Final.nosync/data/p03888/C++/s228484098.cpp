#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double r1,r2,r3=0.0;
    cin>>r1>>r2;
    r1*=1.0;
    r2*=1.0;
    r3=1.0/r1+1.0/r2;
    printf("%.10lf",1.0/r3);
    return 0;
}