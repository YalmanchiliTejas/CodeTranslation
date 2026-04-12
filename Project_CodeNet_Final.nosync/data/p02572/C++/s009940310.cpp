#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10
#define ll long long
#define double long double
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define all(a) (a).begin(), (a).end()
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define endl '\n'
#define mod 1000000007
#define PI 3.14159265359
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define CODE_START  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll n,suf[200005],a[200005];
int32_t main(){
CODE_START;
cin>>n;
for(ll i=1;i<=n;i++)
{
    cin>>a[i];
}
for(ll i=n;i>=1;i--)
{
    suf[i]=suf[i+1]+a[i];
    suf[i]%=mod;
}
ll ans=0;
for(ll i=1;i<=n;i++)
{
    ans+=(a[i]*suf[i+1])%mod;
    ans%=mod;
}
cout<<ans<<endl;
}

