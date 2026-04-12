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
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
int main(){
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans=0;
    map<ll,int> mp;
    ll cnt=0;
    V<ll> d;
    for(int i=0;i<n;i++){
        mp[x]++;
        if(mp[x]==2){
            cnt+=x;
            if(d.size()==0)d.push_back(x);
            else {
                d.push_back(d.back()+x);
            }
        }
        if(mp[x]==3){
            ll len=d.size();
            ans+=cnt*((n-i)/len);
            if((n-i)%len!=0){
             //   cout<<d[(n-i)%len-1]<<"\n";
               // cout<<ans<<"\n";
                ans+=d[(n-i)%len-1];
            }
            break;
        }
        ans+=x;
        x*=x;
        x%=m;
    }
    cout<<ans<<"\n";
}
