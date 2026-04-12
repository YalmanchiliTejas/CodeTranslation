#include <iostream>

using namespace std;

int main()
{
    int x,y,z,nz,m;
    cin>>x>>y>>z;
    m=(x-1)/(y+z);
    nz=z*(m+1);
    if(((m*y)+nz)>x)
    {
        m--;
    }
    cout <<m;
    return 0;
}
