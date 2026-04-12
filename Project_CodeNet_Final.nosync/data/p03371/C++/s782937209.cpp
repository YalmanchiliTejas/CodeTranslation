#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll cost=0;
    ll i=0;
    ll mini=10000000000000000;
    while(1)
    {
        ll temp=0;
        ll p1 = x-i/2;

        ll p2 = y-i/2;
        temp=temp+i*c;
        if(p1<0 && p2<0) break;
        if(p1>0)
        {
            temp+=p1*a;
        }
        if(p2>0)
        {
            temp+=p2*b;
        }
        if(mini>temp && temp!=0) mini=temp;
        i+=2;

    }
    cout<<mini<<endl;
}

