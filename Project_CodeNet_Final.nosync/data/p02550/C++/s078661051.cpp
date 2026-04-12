#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main()
{
    ll i,j,n,x,m;
    cin>>n>>x>>m;
    ll ans = x;
    ll cnt = -1;
    unordered_map<ll,ll> mp;
    mp[x] = 0;
    vector<ll> v;
    v.push_back(x);
    ll cur;
    for(i=1;i<n;i++)
    {
        cur = (v.back()*v.back())%m;
        if(mp.find(cur)!=mp.end()) 
        {
            if(cur==0)
            {
                cout<<ans<<"\n";
                return 0;
            }
            cnt = i;
            break;
        }
        ans+=cur;
        v.push_back(cur);
        mp[cur] = i;
    }
    if(cnt==-1) cout<<ans;
    else
    {
        for(i=mp[cur]+1;i<v.size();i++)
        {
            v[i]+=v[i-1];
        }
        ll sz = cnt - mp[cur];
        ll q = (n-cnt)/sz;
        ll r = (n-cnt)%sz;
        ll res = ans;
        ans = res + (q*v.back());
        if(r!=0) ans+=v[mp[cur]+r-1];
        cout<<ans;
    }
}