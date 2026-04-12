/****JMD****/
/*
Nagendra Jha-11011
acm18in1495
*/
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ll long long int
#define ss second
#define ff first
#define mem(x,val) memset(x,val,sizeof(x))
#define f(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll(a.size())

using namespace std;

inline void display(list<ll> v)
{
    for(auto x:v) cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll a[n];
    f(i,n) cin>>a[i];

    sort(a,a+n);

    ll p1=1,p2=n-2;

    list<ll> g;

    g.pb(a[0]);
    g.pb(a[n-1]);

    bool flag=true;

    while(p1<p2)
    {
        if(flag)
        {
            g.pb(a[p1]);
            g.pf(a[p2]);
            p1++;
            p2--;
            flag=false;
        }
        else
        {
            g.pf(a[p1]);
            g.pb(a[p2]);
            p1++;
            p2--;
            flag=true;
        }
    }

    if(p1==p2)
    {
        if(abs(g.front()-a[p1])>abs(g.back()-a[p1]))
        {
            g.pf(a[p1]);
        }
        else g.pb(a[p1]);
    }

    ll ans=0;

    auto it=g.begin();
    auto temp=g.begin();
    temp++;

    while(temp!=g.end())
    {
        ll v1=(*it);
        ll v2=(*temp);
        ans+=abs((*temp)-(*it));
        it++;
        temp++;
    }

    //display(g);

    cout<<ans;
    return 0;
}
