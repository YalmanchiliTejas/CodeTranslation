#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()
#define pi                  3.14159265359
ll INF=1e18+10;
ll MOD=998244353;//1000000007;

int main()
{
    int n;cin>>n;
    ll a;
    multiset<ll> s;
    rep(i,0,n)
    {
        cin>>a;
        auto x=s.lower_bound(a);
        if(x==s.begin())
            s.insert(a);
        else
        {
            x--;
            if(*x==a)
                s.insert(a);
            else
                s.erase(x),s.insert(a);
        }
    }
    cout<<s.size()<<endl;
}
