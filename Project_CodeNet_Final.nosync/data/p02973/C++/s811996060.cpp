#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e5+5;
int mod=1e9+7;

ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}
int arr[N];

int main()
{
    FIO
    set<pair<int,int>>st;
    int n;
    cin>>n;
    int co=0;
    set<pair<int,int>> ::iterator it;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
for(int i=n-1;i>=0;i--)
{
    int x=arr[i];
    it=st.upper_bound({x,1e9});
    if(it==st.end())
    {
       /// cout<<"notfound "<<x<<endl;
        co++;
        st.insert({x,co});
    }
    else
    {
    ///    cout<<"found--> "<<it->first<<" "<<it->second<<" \n";
        int f=it->second;
        st.erase(it);
        st.insert({x,f});

    }

}
        cout<<co;

    return 0;
}

