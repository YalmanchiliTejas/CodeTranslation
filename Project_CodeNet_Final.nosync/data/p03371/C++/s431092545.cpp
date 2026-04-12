#include <iostream>

using namespace std;

int main()
{
    int a,b,c,x,y,s=0;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    if(a+b>c)
    {
        if(x>y)
        {
            s+=c*y;
            x=x-y;
            y=0;
            if(a>c)
                s+=c*x;
            else
                s+=a*x;
        }
        else
        {
            s+=c*x;
            y=y-x;
            x=0;
            if(b>c)
                s+=c*y;
            else
                s+=b*y;
        }
    }
    else
        s=x*a+y*b;
    cout<<s;
    return 0;
}
