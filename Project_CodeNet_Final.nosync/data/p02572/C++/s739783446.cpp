#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define fastAF ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define pb push_back
#define pf push_front
#define dll deque<ll>
#define vll vector<ll>
#define pll pair<ll,ll>
#define mapll map<ll,ll>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
void swap(auto*,auto*);
const ll p=1e9+7;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastAF
    ll n; cin>>n; ll a[n]; for(ll i=0;i<n;i++) cin>>a[i];
    ll pre[n+1]; pre[0]=0; for(ll i=0;i<n;i++) pre[i+1]=(pre[i]+a[i])%p;
    ll ans=0;
    for(ll i=n-1;i>=0;i--)
    {
    	ans=(ans+(a[i]*pre[i])%p)%p;
    }
    cout<<ans<<endl;
    return 0;
}
void swap(auto &a,auto &b)
{
    auto temp=a; a=b; b=temp;
}