#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,m,n) for(ll i=m;i<n;i++)
#define all(v) v.bigin(),v.end()
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define R(a) a=sqrt(a)
#define POW(a,b) a=pow(a,b)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    FAST;
    ll n,all,all2;
    cin>>n;
    ll a[n];
    all=0;
    rep(i,n){
        cin>>a[i];
        all+=a[i];
    }

    ll ans;
    ans=0;
    rep(i,n){
        all-=a[i];
        all2=all%1000000007;
        ans+=(a[i]*all2)%1000000007;
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}

