#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((b*2+c)%4==0) printf("YES");
    else printf("NO");
    return 0;
}