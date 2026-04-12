#include <bits/stdc++.h>
//Fast io
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//Class shorthands
#define ll long long
#define db long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
//Function Shorthands
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define po pop_back
#define eb emplace_back
//Code Shorthands
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
//Constants
#define hell 1000000007
#define PI acos(-1.0)
using namespace std;
ll binexpo(ll a, ll b, ll c){
    //if(b<0) return 0;
    if(!b) return 1;
    if(b&1) return (binexpo((a*a)%c, b>>1,c)*a)%c;
    return binexpo((a*a)%c, b>>1,c)%c;
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    ll s = 0;
    for(auto i: a) s+=i;
    s%=hell;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll cur = (s-a[i]+hell)%hell;
        ans += (cur*a[i])%hell;
        ans%=hell;
    }
    ans = (ans*binexpo(2, hell-2, hell))%hell;
    cout<<ans<<endl;
}

int main(){
    io;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}