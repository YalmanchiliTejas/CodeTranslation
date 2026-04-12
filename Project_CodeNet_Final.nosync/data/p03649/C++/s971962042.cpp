#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
//const ll mod=1000000007;
int GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(5);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    ll n;
    cin>>n;
    bool able=false;
    V<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=n)able=true;
    }
    if(!able){
        cout<<0<<"\n";
        return 0;
    }
    ll bfo=0,inc=0;
    ll ans=0;
    while(1){
        bfo=inc;
        inc=0;
        able=false;
        for(int i=0;i<n;i++){
            if(bfo+a[i]>=n){
                able=true;
               ll d=(bfo+a[i])/n;
               inc+=d;
               a[i]=(bfo+a[i])%n;
               a[i]-=d;
            }else{
                a[i]+=bfo;
            }
        }
        ans+=inc;
        if(!able)break;
    }
    cout<<ans<<"\n";
}
