#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    ll m;
    cin>>m;
    ll prev=x;
    ll sum=x;
    map<ll,ll> mp;
    mp[x]=1;
    vector<ll> tmp;
    tmp.push_back(x);
    ll req;
    int id;
    for(ll i=2; i<=n; i++)
    {
        prev=(prev*prev)%m;
        tmp.push_back(prev);
        if(prev==0)
        {
            break;
        }
        if(mp[prev]==1)
        {
            id=i;
            req=prev;
            break;
        }
        sum +=prev;
        mp[prev]=1;
        //getchar();
    }
    tmp.pop_back();
    reverse(tmp.begin(),tmp.end());
    while(tmp.size() && tmp.back()!=req)
    {
        tmp.pop_back();
    }
    reverse(tmp.begin(),tmp.end());
    if(tmp.size())
    {
        id--;
        ll op=0;
        for(int i=0;i<tmp.size();i++)
        {
            op += tmp[i];
        }
        ll baki=n-id;
        ll sz=tmp.size();
        ll ex=baki/sz;
        sum += (op*ex);
        ex=baki%sz;
        for(int i=0;i<ex;i++)
        {
            sum += tmp[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}
