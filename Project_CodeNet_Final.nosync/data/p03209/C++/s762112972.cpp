#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1000000000000000
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a);  a = (a * a);  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const ll N = 100003;
ll n,k;
ll go(ll n,ll k)
{
    if(k == 0)
        return 0;
    if(n == 0)
        return 1;
    ll g = modexp(2LL,n + 2) - 3;
    if(k == g)
        return modexp(2LL,n + 1) - 1;
    g /= 2;
    ll res;
    if(k <= g)
        res = go(n - 1,k - 1);
    else
        res = go(n - 1,g - 1) + 1 + go(n - 1,k - g - 1);
    return res;
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    cout<<go(n,k);
    return 0;
}