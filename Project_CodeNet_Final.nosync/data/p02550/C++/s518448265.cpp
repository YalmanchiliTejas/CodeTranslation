#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;  
#define ordered_set tree<ll, null_type , less<ll> , rb_tree_tag , tree_order_statistics_Node_update> 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define inf 1e18
#define mk make_pair
#define ld long double
#define mod 1000000007
#define fi first
#define se second
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test ll t; cin>>t; while(t--)
#define setbits __builtin_popcount
#define endl '\n'
#define LOCAL
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
int main()
{
    fastIO;
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll>dp(100001);
    map<ll,ll>mp;
    dp[0]=x;
    mp.insert({dp[0],0});
    ll val,val1=1,val2=-1,ans=0,val3;
    for(int i=1;i<100001;i++)
    {
        dp[i]=(dp[i-1]*dp[i-1])%m;
        if(mp.find(dp[i])==mp.end())
        {
            val1++;
            mp.insert({dp[i],i});
        }
        else
        {
            val3=mp[dp[i]];
            break;
        }
    }   
    if(n==1)
    {
        cout<<dp[0]<<endl;
    }   
    else
    if(n==2)
    {
        cout<<dp[1]+dp[0]<<endl;
    }
    else
    {
        val=0;
        val1-=val3;
        for(int i=val3;i<val1+val3;i++)
        {
            val+=dp[i];
        }
        n-=val3;
        val2=n%val1;
        ans+=val*(n/val1);
        for(int i=0;i<val3+val2;i++)
        {
            ans+=dp[i];
        }
        cout<<ans<<endl;
    }
    //debug()<<dp;
}
