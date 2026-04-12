#include<iostream>
#include<cstdio>
using namespace std;
int main ()
{
    int r1,r2;
    double r3 ;
    scanf("%d %d",&r1,&r2);
    if((r1 >= 1 && r1 <= 100) && (r2 >= 1 && r2 <= 100 ))
    {
        r3 = double(1.0/r1) + double(1.0/r2) ;
        r3 = 1.0/r3 ;
        printf("%.10f\n",r3);

    }

    return 0 ;
}