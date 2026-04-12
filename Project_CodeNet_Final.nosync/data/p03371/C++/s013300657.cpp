#include <iostream>
using namespace std;

int a,b,c,x,y;

int main()
{
    int impart;
    unsigned long long sol=0;
    cin>>a>>b>>c>>x>>y;
    if(a+b>2*c)
    {
        impart=min(x,y)*2;
        sol+= impart*c;
        if(2*c<a)
            sol+=2*c*(x-min(x,y));
        else
            sol+= (x-min(x,y))*a;

        if(2*c<b)
            sol+=2*c*(y-min(x,y));
        else
            sol+= (y-min(x,y))*b;
    }
    else
    {
        sol+=x*a;
        sol+=y*b;
    }
    cout<<sol<<'\n';
    return 0;
}
