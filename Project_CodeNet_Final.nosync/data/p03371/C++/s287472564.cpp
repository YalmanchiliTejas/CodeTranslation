#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,x,y,mn,mx,d;
    cin>>a>>b>>c>>x>>y;
    mn=min(x,y);
    mx=max(x,y);
    if(mn==x)
        d=(mx-mn)*b;
    else
        d=(mx-mn)*a;
    cout<<min({(a*x)+(b*y),mx*c*2,((mn*2)*c)+d})<<endl;
}
