/*
        Author: Prokash
                CSE48, JU

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    FAST;
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if((a+b)<2*c)
    {
        cout<<a*x+b*y<<endl;
        return 0;
    }
    else

    {
        if(x>y)
        {
            if(2*c<a)
            {
                cout<<2*c*x<<endl;
                return 0;
            }
            else

            {
                cout<<2*c*y+a*(x-y)<<endl;
                return 0;
            }
        }
        else
        {
            if(2*c<b)
            {
                cout<<2*c*y<<endl;
                return 0;
            }
            else
            {
                cout<<2*c*x+b*(y-x)<<endl;
                return 0;
            }
        }
    }
    return 0;
}