// بِسمِ اللہِ  الرَّحم?نِ  الرَّ حِیم
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define INF 1e18
#define N 100100
#define PI 3.141592653589793238
typedef pair<ll,ll> pll;
ll power(ll a,ll b)
{
    if(b==1)return a;
    if(b==0)return 1;
    ll temp=power(a,b/2);
    ll ans=temp*temp;
    if(b&1)
        ans*=a;
    return ans;
}
ll power(ll a,ll b,ll p)
{
    a=a%p;
    if(b==1)return a;
    if(b==0)return 1;

    ll temp=power(a,b/2,p);
    ll ans=(temp*temp)%p;
    if(b&1)
        ans=(a*ans)%p;
    return ans%p;
}
ll inv(ll a,ll m)
{
    return power(a,m-2,m);
}
//code begins
void solve(){
    ll x;cin>>x;
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
}
signed main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);

//    ll t;cin>>t;while(t--)
    solve();
    return 0;
}
