#include<iostream>
using namespace std;

int main()
{
    int a,b,c,x,y;

    while(cin>>a>>b>>c>>x>>y)
    {
        int small=min(x,y);
        int result;
        if(a+b<2*c)
            result=a*x+b*y;
        else
        {
            if(x>y)
            {
                if(a>2*c)
                    result=x*2*c;
                else
                    result=small*2*c+(x-small)*a;
            }
            else
            {
                if(b>2*c)
                    result=y*2*c;
                else
                    result=small*2*c+(y-small)*b;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
