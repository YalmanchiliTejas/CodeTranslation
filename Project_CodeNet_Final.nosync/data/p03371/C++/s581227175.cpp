#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int a,b,c,d,e,x,y,l;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c)
    {
        e=x*a+y*b;
    }
    else
    {
        if(x>=y)
        {
            d=y;
            l=x-y;
            e=c*2*d;
            if(a<=2*c)
                e+=a*l;
            if(a>2*c)
                e+=2*c*l;
        }
        else
        {
            d=x;
            l=y-x;
            e=c*2*d;
            if(b<=2*c)
                e+=b*l;
            if(b>2*c)
                e+=2*c*l;
        }
    }
    cout<<e<<endl;
    return 0;
}
