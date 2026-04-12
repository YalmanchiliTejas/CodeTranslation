#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
 
using namespace std;
 
int main()
{
    double R1, R2;
    if (scanf("%lf%lf", &R1, &R2) < 2) return 0;
 
    printf("%.10lf\n", R1 * R2 / (R1 + R2));
    return 0;
}