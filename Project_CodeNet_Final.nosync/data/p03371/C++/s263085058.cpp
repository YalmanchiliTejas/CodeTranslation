#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int (i) = 0ll; (i) < (n); ++(i))
#define repp(i,n) for(int (i) = 1; (i) <= (n); ++(i))
#define popcnt __builtin_popcount
#define all(v) v.begin(),v.end()
#define _Pi 3.1415926535
#define _MOD = 1e9+7;
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using itn = int;
using vint = vector<int>;
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b; return true;} return false;}
template<class T> T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a, T b){return a*b/gcd(a,b);}

int main(){
    ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;

    if(a+b<=c*2){
        cout << a*x + b*y << endl;
    }
    else if(a <= c*2 && b <= c*2){
        cout << min(x,y)*c*2 + (x-min(x,y))*a + (y-min(x,y))*b << endl;
    }
    else if(a > c*2 && b > c*2){
        cout << max(x,y)*c*2 << endl;
    }
    else if(a > c*2 && b <= c*2){
        cout << x*c*2 + max(0ll,y-x)*b << endl;
    }
    else if(a <= c*2 && b > c*2){
        cout << y*c*2 + max(0ll,x-y)*a << endl;
    }
    

    return 0ll;
}
