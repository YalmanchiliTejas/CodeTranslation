#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x,y,z;
    while(scanf("%d%d%d",&x,&y,&z)==3)
    cout<<(x-z)/(y+z)<<endl;
    return 0;
}
