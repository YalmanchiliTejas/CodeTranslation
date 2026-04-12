#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

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
    //cout<<edge<<endl;
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
        //cout<<ans<<endl;
    }
    if(edge<=x)ans++;
     
    cout<<ans;
    
    

}
