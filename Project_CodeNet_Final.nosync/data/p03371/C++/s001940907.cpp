#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll price = LONG_LONG_MAX;
    rep(i,0,1e5+1){
        ll p = 2*c*i + a*max(0LL,x-i) + max(0LL,y-i)*b;
        price = min(p,price);
    }
    cout << price << endl;
    return 0;
}