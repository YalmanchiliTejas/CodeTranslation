#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,s,c;
    scanf("%d",&n);
    s=n*800;
    c=n/15;
    s=s-c*200;
    printf("%d\n",s);
    return 0;
}
