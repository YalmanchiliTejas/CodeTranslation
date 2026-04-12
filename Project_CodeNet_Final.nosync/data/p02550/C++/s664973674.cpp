//Life is inherently meaningless unless you find something which gives it meaning
 

#include<bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define fora(it,x) for(auto it:x)
#define PI 3.14159265
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
 
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef long double ld;
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main(){
    ll n,x,m,s=0;
    cin>>n>>x>>m;
    map<ll,ll> mm;
    vector<ll> v;

    if(n<=m){
        ll ans=0;
        for1(i,n){
            ans=(ans+x);
            //cout<<x<<" ";
            x=(x*x)%m;
        }
        cout<<ans<<endl;
        return 0;
    }

    ll a=x,cur=0,start=-1,ans=0;
    while(1){
        //cout<<a<<" ";
        auto it=mm.find(a);
        if(it!=mm.end()){
            start=(it->se)+1;
            break;
        }
        v.pb(a);
        mm.insert(mp(a,cur));
        a=(a*a)%m;
        cur++;
    }
    //for(auto x:v) cout<<x<<" ";
    ll len=(v.size()-start+1); //length of the loop
    //cout<<len<<" ";
    if(n<start){
        for(ll i=1;i<=n;i++){
            ans=(ans+v[i-1]);
        }
        cout<<ans<<endl;
        return 0;
    }
    
    for(ll i=0;i<start-1;i++){
            ans=(ans+v[i]);
    }
    //cout<<ans<<" "<<start<<" ";
    n-=(start-1);
    //ll s=0;
    for(ll i=start-1;i<v.size();i++){
        s=(s+v[i]);
    }
    ans=(ans+((n/len)*s));
    n=n%len;
    for(ll i=start-1;i<=start+n-2;i++){
        ans=(ans+v[i]);
    }
    cout<<ans;
}