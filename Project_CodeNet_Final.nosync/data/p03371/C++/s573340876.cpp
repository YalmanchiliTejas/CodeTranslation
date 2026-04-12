#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    ll res=a*x+b*y;
    if(x>y) chmin(res, c*2*y+a*(x-y));
    else chmin(res, c*2*x+b*(y-x));
    chmin(res, c*2*max(x,y));
    cout<<res<<endl;
    return 0;
}