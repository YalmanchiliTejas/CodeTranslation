#include<bits/stdc++.h>
#define  ll   long long int
#define  sz   20010

using namespace std;

ll num[10];

int main()
{


    ll a,b,c,x,y,n,m,i,j,k,p,s,d;

    cin>>a>>b>>c>>x>>y;

    p=a+b;

    d=min(x,y);

    n=d*2*c;
    m=(a*d)+(b*d);
    s=min(n,m);

    //cout<<s<<endl;


    if(x>y)
    {
        d=x-y;

        n=d*a;
        m=(d*c*2);
        s+=min(n,m);

    }
    else if(y>x)
    {
        d=y-x;

        n=d*b;
        m=(d*c*2);
        s+=min(n,m);

    }
    cout<<s<<endl;

    return 0;
}

