#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int x,y,z,i;
    cin>>x>>y>>z;
    for(i = x/y;i >= 0;i --)
    {
        if(x >= y*i + z + z * i)break;
    }
    cout<<i;
}
