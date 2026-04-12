#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    double a, b;
    cin >> a >> b;
    printf("%.6f\n", (a * b) / (a + b));
    return 0;
}