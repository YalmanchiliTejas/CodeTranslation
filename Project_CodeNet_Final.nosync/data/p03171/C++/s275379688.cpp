// Author : Chi
// created : Sunday 2020-05-31
// Sawal : https://www.codechef.com/LTIME84B/problems/TREDIFF

//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//macros
#define ll 		    long long
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb(x)       push_back(x)
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define TEST1       solve();
#define mod         998244353
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define db(...)     __f(#__VA_ARGS__, __VA_ARGS__)                      //for debugging
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
//LOVE ALGO
ll maxi(ll *a,ll s,ll e);
ll dpma[3000][3000];
ll dpmi[3000][3000];
ll mini(ll *a,ll s,ll e){
    if(s==e)
        return 0;
    if(dpmi[s][e]!=-1)
        return dpmi[s][e];
    ll ans1=maxi(a,s+1,e);
    ll ans2=maxi(a,s,e-1);
    return dpmi[s][e]=min(ans1,ans2);
}
ll maxi(ll *a,ll s,ll e){
    if(s==e)
        return a[s];
    if(dpma[s][e]!=-1)
        return dpma[s][e];
    ll ans1=a[e]+mini(a,s,e-1);
    ll ans2=a[s]+mini(a,s+1,e);
    return dpma[s][e]=max(ans1,ans2);
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll s=0;
    memset(dpma,-1,sizeof dpma);
    memset(dpmi,-1,sizeof dpmi);
    r0n(i,n){
        cin>>a[i];
        s+=a[i];
        }
    ll A=maxi(a,0,n-1);
    ll B=s-A;
    cout<<A-B;
}

// Driver Code
int main(){
    CHI
    TEST1
    return 0;
}

