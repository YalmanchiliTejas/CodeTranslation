#include"bits/stdc++.h"
#define INFLL        1e18
#define REP(i,n)     for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)    for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)    for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)   for(ll i=(n);i>0;--i)
#define REPC(i,obj)  for(auto i:obj)
#define ALL(obj)     (obj).begin(),(obj).end()
#define SETP(n)      cout<<fixed<<setprecision(n)
#define DELNL        cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define VV(T,h,w)    vector<vector<T>>(h,vector<T>(w))
#define VVI(T,h,w,i) vector<vector<T>>(h,vector<T>(w,i))
using namespace std;
using ll=long long;
using ull=unsigned long long;
template<typename T>using pqg=priority_queue<T,vector<T>,greater<T>>;
template<typename T=ll>inline T in(){T ret;cin>>ret;return ret;}

int main()
{
    ll n=in();
    vector<ll>h(n);REP(i,n)h[i]=in();
    ll minh=-INFLL,ans=0;
    REP(i,n){
        if(h[i]>=minh){
            ++ans;
            minh=h[i];
        }
    }
    cout<<ans<<endl;
}