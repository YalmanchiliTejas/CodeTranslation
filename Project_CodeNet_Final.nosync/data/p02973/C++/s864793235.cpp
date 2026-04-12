#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long
#define mod (long long)(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))



ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2)%mod ;
    res=((res)*(res))%mod ;
    if(p%2)
        res=(res*n)%mod ;
    return res ;
}


vector< int> v;



int main()
{
    ENGZ;
    int n , a ;
    cin>>n ;
    for(int i=0 ; i<n; i++)cin>>a,v.push_back(a) ;
    map<int,int> mp;
    for(int i=sz(v)-1 ; i>=0 ; i--)
    {
        auto it = mp.upper_bound(v[i]);
        if(it != mp.end())
        {
            it->second -- ;
            if(it->second == 0)mp.erase(it);
        }
        mp[v[i]]++ ;
    }
    int ans = 0 ;
    for(auto i:mp)
        ans += i.second ;
    cout<<ans <<endl ;
    return 0;
}
