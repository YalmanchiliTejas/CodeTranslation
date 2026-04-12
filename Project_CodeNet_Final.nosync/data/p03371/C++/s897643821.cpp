#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll i,j,a,b,c,x,xx,y,yy,direct=0,bya=0,byb=0;
    cin>>a>>b>>c>>x>>y;
    xx=x;
    yy=y;
    direct=x*a+y*b;
    bya=2*x*c;
    y-=x;
    if(y>0)
        bya+=(y*b);


    byb=2*yy*c;
    xx-=yy;
    if(xx>0)
        byb+=(xx*a);
    //cout<<direct<<" "<<bya<<" "<<byb<<endl;
    cout<<min(direct,min(bya,byb))<<endl;

    return 0;
}



