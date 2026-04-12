#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    long long A,B,X,C,Y;
    scanf("%lld %lld %lld %lld %lld",&A,&B,&C,&X,&Y);
    int flag=1;
    if(2*C>A+B)
        flag=0;
    long long jiage=0;
    long long jia;
    if(flag==1)
    {
        long long temp;
        temp=min(X,Y);
        jiage=temp*2*C;
        if(X>Y)
        {
            temp=X-Y;
            jia=A;
        }
        else
        {
            temp=Y-X;
            jia=B;
        }
        if(2*C<jia)
            jiage=jiage+temp*2*C;
        else
            jiage=jiage+temp*jia;
    }
    else
    {
        jiage=A*X+Y*B;
    }
    printf("%lld\n",jiage);
    return 0;
}
