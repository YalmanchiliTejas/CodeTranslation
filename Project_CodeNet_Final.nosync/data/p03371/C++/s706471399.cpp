#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    while (cin>>a>>b>>c>>x>>y)
    {
        int n;
        if (((a+b)/2)>=c)
        {
            if (x>y)
            {
                if (a>c*2)
                {
                    n=c*y*2+(x-y)*c*2;
                }
                else
                {
                    n=y*2*c+(x-y)*a;
                }
                cout<<n<<endl;
            }
            else
            {
                if (b>c*2)
                {
                    n=c*x*2+(y-x)*c*2;
                }
                else
                {
                    n=x*2*c+(y-x)*b;
                }
                cout<<n<<endl;
            }
        }
        else
        {
            n=a*x+b*y;
            cout<<n<<endl;
        }

    }
    return 0;
}
