#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,ab,x,y,pr=0;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&ab,&x,&y);
    ll ans=((a*x)+(b*y));
    if(x>y)
    {
        pr=((2*y*ab)+(x-y)*a);
        ll aa=(2*x*ab);
        //cout<<aa<<endl;
        pr=min(pr,aa);
    }
    else
    {
        pr=((2*x*ab)+(y-x)*b);
        ll aa=(2*y*ab);
        //cout<<aa<<endl;
        pr=min(pr,aa);
    }
    cout<<min(pr,ans)<<endl;
    return 0;
}
