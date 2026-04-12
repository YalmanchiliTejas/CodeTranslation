#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    ll res=a*x+b*y;
    for(ll i=1; i<=max(x, y); i++){
        ll tmp=a*max(x-i, 0ll) + b*max(y-i, 0ll) + c*2*i;
        chmin(res, tmp);
    }
    cout<<res<<endl;
    return 0;
}