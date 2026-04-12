//@sakshjha
#include<bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

#define ll  long long  int
#define ld   long double
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pi 3.14159265358979
//#define goodset tree<pa, null_type, less<pa>, rb_tree_tag, tree_order_statistics_node_update>
//#define FRE freopen("acm.in","r",stdin); freopen("acm.out","w",stdout);

const ll mod = 1e9+7 ;
const ll N = 1e5+5;


int main()
{
    FAST
    ll i,j,k,tc;
    //cin>>tc;
    tc=1;
    while(tc--)
    {
        ll n,x,m;
        cin>>n>>x>>m;

        vector<ll>v;
        map<ll,ll>mp;
        ll ans=0;
        if(n<=1e6)
        {
            ll pres=x;
            for(i=1; i<=n; i++)
            {
                ans+=x;
                x=((x*x)%m);
            }
            cout<<ans<<"\n";
            return 0;
        }

        ll st=-1, siz=-1;
        for(i=1; i<=1e6; i++)
        {
            if(mp.find(x)!=mp.end())
            {
                st=mp[x]-1;
                siz=i-mp[x];
                break;
            }
            else
            {
                ans+=x;
                v.pb(x);
                mp[x]=i;
                x=(x*x)%m;
            }
        }

        ll sum=0;
        ll left=n-(i-1);
        for(i=st; i<st+siz; i++)
            sum+=v[i];

        ll cnt1=left/siz;
        ans+=(cnt1*sum);
        left%=siz;
        for(i=st; i<st+left; i++)
            ans+=v[i];

        cout<<ans<<"\n";




    }

    return 0;
}
