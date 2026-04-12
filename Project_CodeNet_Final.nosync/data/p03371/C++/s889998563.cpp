#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1e9+7;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll price = LONG_LONG_MAX;
    rep(i,1e5+1){
        ll p = 2*c*i + a*max(0LL,x-i) + b*max(0LL,y-i);
        price = min(p,price);
    }
    cout << price << endl;
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/