#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int cost=0;
    if(min(x,y)*(a+b)>2*min(x,y)*c)
        cost+=2*min(x,y)*c;
    else
    {
        cost+=min(x,y)*(a+b);
    }
    int k=0;
    if(x>=y)
    {
        k=x-y;
        cost+=min(a*k,2*k*c);
    }
    else
    {
        k=y-x;
        cost+=min(b*k,2*k*c);
    }
    cout<<cost;
    return 0;
}
