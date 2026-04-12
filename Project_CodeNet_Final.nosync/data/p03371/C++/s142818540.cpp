#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,x,y,l,sum=0;
    cin>>a>>b>>c>>x>>y;
    if(c*2<=a&&c*2<=b)
    {
        if(x>y)
        {
            x=x*2;
            c=c*x;
            cout<<c<<endl;
            return 0;
        }
        else
        {
            y=y*2;
            c=c*y;
            cout<<c<<endl;
            return 0;
        }
    }
    if(x>y)
    {
        l=y;
    }
    else
    {
        l=x;
    }
    if((2*c)<=(a+b))
    {
         x-=l;
        y-=l;
        l=l*2;
        sum+=l*c;


    }

    if(2*c<=a&&x>0)
    {
        x=x*2;
        sum+=x*c;
    }
    else if(x>0)
    {
        sum+=a*x;
    }
    if(2*c<=b&&y>0)
    {
        y=y*2;
        sum+=y*c;
    }
    else if(y>0)
    {
        sum+=b*y;
    }
    cout<<sum<<endl;
}
