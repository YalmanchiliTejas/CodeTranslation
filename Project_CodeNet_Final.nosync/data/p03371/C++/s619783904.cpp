using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;
ll mod9 = 1000000009;

signed main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll sumf = a*x+b*y;
    ll ta,tb,tc,ts,res;
    rep(i,1+2*max(x,y)){
        ta =tb = ts =0;
        ta = max(0LL,x-(i/2));
        tb = max(0LL,y-(i/2));
        ts = ta*a+tb*b+i*c;
        if(!i) res = ts;
        else res = min(res,ts);
    }
    cout<<res<<endl;
}
