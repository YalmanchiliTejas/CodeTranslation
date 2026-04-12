#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
typedef short int si;
typedef long long int ll;
typedef long int li;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<li,li> pli;
typedef pair<ll,ll> pll;
#define Max 1000001
#define inf INT_MAX
#define linf LONG_MAX 
#define llinf LONG_LONG_MAX
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rrep(i,a,b) for(i=a;i>=b;i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define mkp make_pair
#define F first
#define S second
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define endl '\n'
const ll N=11;
ll mod=1e9+7;
signed main()
{
    fast;
    ll pro=1,temp,n,m,k,t,i,j,l,r,mid,x,y,z,rem,carry=0,ind,ans=0,mx=-llinf,mn=llinf,cnt=0,curr=0,prev,sum=0,flag=0,i1=-1,i2=-1;
    cin>>n;
    ll a[n];
    multiset<ll> ms;
    multiset<ll>::iterator it;
    rep(i,0,n-1)
    {
        cin>>a[i];
        it=ms.lb(a[i]);
        if(it==ms.begin())
        {
            ms.insert(a[i]);
        }
        else
        {
            ms.erase(--it);
            ms.insert(a[i]);
        }
    }
    cout<<ms.size();
    return 0;
} 
 