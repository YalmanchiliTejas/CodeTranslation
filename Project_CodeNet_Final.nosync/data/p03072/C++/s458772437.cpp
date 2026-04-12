#include <bits/stdc++.h>
 
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main(){
    ll n,ans=1;
    cin>>n;
    ll max_h;
    cin>>max_h;
    rep(i,n-1){
        ll h;
        cin>>h;
        if(h>=max_h){
            ans++;
            max_h=h;
        }
    }
    cout<<ans<<endl;
}
   

