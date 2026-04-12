#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>vec;
ll vis[100009];

int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    scanf("%lld%lld%lld",&n,&x,&m);
    vis[x]=1;
    a=x;
    vec.push_back(a);
    while(1)
    {
        a=(a*a)%m;
        if(vis[a]==1)
        {
            break;
        }
        else
        {
            vis[a]=1;
            vec.push_back(a);
        }
    }

    l=vec.size();
    k=min(l,n);
    ll ans=0;
    for(i=0;i<k;i++)
    {
        ans+=vec[i];
    }
    n-=k;
    x=0;
    y=0;
    for(i=0;i<l;i++)
    {
        if(vec[i]==a)
        {
            for(k=i;k<l;k++)
            {
                x+=vec[k];
                y++;
            }
            j=i;
            break;
        }
    }
    a=n/y;
    b=n%y;
    ans+=(a*x);
    for(i=j;i<l;i++)
    {
        if(b>0)
        {
            ans+=vec[i];
            b--;
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
}
