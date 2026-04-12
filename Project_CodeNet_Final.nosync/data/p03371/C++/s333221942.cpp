#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,i,j,a1,a2,ans,t,a,b,c,x,y;
    while(cin>>a>>b>>c>>x>>y)
    {
        if(a+b>c+c)
        {
            int p=min(x,y);
            int q=max(x,y);
            a1=p*2*c;
            a1+=(x-p)*min(2*c,a);
            a1+=(y-p)*min(b,2*c);
             a2=q*2*c;
            ans=min(a1,a2);
        }
        else
            ans=x*a+y*b;
        cout<<ans<<endl;

    }
    return 0;
}

