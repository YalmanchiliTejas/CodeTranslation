#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue
#define    nl           "\n"
#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase
#define lb lower_bound
#define ub upper_bound

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mpi map<int,int>
#define mpl map<ll,ll>
#define umpi unordered_map<int,int>
#define umpl unordered_map<ll,ll>
#define si set<int>
#define sl set<ll>
#define msi multi_set<int>
#define msl multi_set<ll>

#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);


#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define reprab(i,a,b) for(int i=(a);i>=(b);i--)
#define repll(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)
#define tc int t;cin>>t;while(t--)




int main()
{   
    
    fast
    ll n;
    cin>>n;
    vll a(n),pre(n);
    rep(i,n)cin>>a[i];
    pre[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        pre[i]=pre[i+1]+a[i];
    }
    ll ans=0;
    rep(i,n){
        ll p=((a[i]%mod)*((pre[i]-a[i])%mod))%mod;
        ans=(ans+p)%mod;
    }
    cout<<ans<<nl;
    return 0;
}