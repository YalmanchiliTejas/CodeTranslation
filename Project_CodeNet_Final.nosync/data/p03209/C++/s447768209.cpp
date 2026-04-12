#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;

ll get(ll x,ll fn[], ll n)
{
    //cout<<"at x = "<<x<<"\n";
    if(x == 0)
        return 0;
    if(x == 1)
        return 0;
    if(fn[n-1]+1>x)
        return get(x-1,fn,n-1);
    if(fn[n-1] + 1 == x)
        return (1ll<<(n)) - 1;
    if(fn[n-1] + 2 == 2)
        return (1ll<<(n));
    if(2*fn[n-1]+2 > x)
        return (1ll<<(n)) + get(x-fn[n-1]-2,fn,n-1);
    return 2*((1ll<<n)-1) + 1;
    
    /*if(x <= 1)
        return x;
    ll ind=0;    
    for(ll i=1;i<53;i++)
    {
        if(fn[i] == x)
            return (1ll<<(i+1) - 1);
        if(fn[i]>x)
        {
            ind = i-1;
            break;
        }
    }
    
    //cout<<"at x = "<<x<<" ind = "<<ind<<"\n";
    
    if(x == fn[ind] + 1)
        return (1ll<<(ind+1) - 1);
    if(x == fn[ind] + 2)
        return (1ll<<(ind+1));
    if(x == 2*fn[ind] + 2)    
        return 2*((1ll<<(ind+1) - 1)) + 1;
    return (1ll<<(ind+1)) + get(x-fn[ind]-2,fn);    */
}

int main()
{
   FAST/**/
   
   ll n,x;
   cin>>n>>x;
   
   ll fn[53];
   fn[0] = 1;
   for(ll i=1;i<53;i++)
        fn[i] = 2*fn[i-1] + 3;
   
   ll ans = get(x,fn,n);
   cout<<ans;
   
   
   return 0;
}