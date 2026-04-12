#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main() {
    ll a,b,c,x,y,ans=1000000000;
    cin>>a>>b>>c>>x>>y;
    for(ll i=0;i<=2*max(x,y);i+=2){
        ll k=i*c;
       // k+=max(0,1);
       ll zero=0;
        k+=max(zero,x-i/2)*a;
        k+=max(zero,y-i/2)*b;
        ans=min(k,ans);
    }
    cout<<ans<<endl;
    
}

