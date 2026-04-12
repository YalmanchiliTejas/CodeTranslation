#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1000000007;
const double PI = 3.141592653589793238463;
const ll N=2e5+9;
int main()
{
    FASTINOUT;
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int mn=min(x,y);
    ll ans=0;
    if (c*2<=a+b)
    {
        ans=c*2*mn;
        x-=mn,y-=mn;
        if (x)
        {
            if (c*2<=a)
                ans=ans+2*c*x;

            else
                ans+=a*x;

        }
        else if (y)
        {
            if (c*2<=b)
                ans=ans+2*c*y;

            else
                ans+=b*y;
        }
        cout<<ans<<endl;
    }
    else
        cout<<a*x+b*y<<endl;
    return 0;
}
