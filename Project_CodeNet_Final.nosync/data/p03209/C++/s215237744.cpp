#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

ll pathy(int level)
{
    return 1+2*(pow(2,level)-1);
}

ll buger(int level)
{
    if(level==0)
    {
        return 1;
    }
    return 1+4*(pow(2,level)-1);
}

int main()
{
    int n;
    ll x;
    ll ans=0;
    cin>>n>>x;
    int currentlevel=n;
    ll edge=buger(n);
    ll start=1;
    while(edge-start>0)
    {
        ll point=(edge+start)/2;
        if(x==point)
        {
            ans+=pathy(currentlevel-1)+1;
            cout<<ans;
            return 0;
        }
        if(x<point)
        {
            edge=point-1;
            start+=1;
        }
        else
        {
            ans+=pathy(currentlevel-1)+1;
            start=point+1;
            edge-=1;
        }
        currentlevel-=1;
    }
    if(edge<=x)ans++;
     
    cout<<ans;
    
    

}
