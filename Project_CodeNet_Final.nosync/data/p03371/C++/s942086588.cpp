#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(2*c>a+b)cout<<a*x+b*y;
    else
    {
        if(x>y)
        cout<<y*c*2+min(2*c,a)*(x-y);
        else
        cout<<x*2*c+(y-x)*min(b,c*2);
    }
    return 0;
}
