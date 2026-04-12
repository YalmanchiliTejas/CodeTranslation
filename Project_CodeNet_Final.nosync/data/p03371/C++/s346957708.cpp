#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int aa, bb, ab, x, y;
    cin >> aa >> bb >> ab >> x >> y;
    x *= 2; y *= 2;
    //cout << "aa:" << aa << " bb:" << bb << " ab:" << ab << ln;
    //cout << "x:" << x << " y:" << y << ln;

    int res = 0;
    if(2 * ab < aa + bb){
        res += min(x, y) * ab;
        //cout << "res:" << res << ln;
        int value;
        if(x > y) value = aa; else value = bb;
        //cout << "value:" << value << " 2ab:" << ab * 2 << ln;
        if(value < 2 * ab)
            res += value * abs(x-y) / 2;
        else
            res += ab * abs(x-y);
    } else{
        res += aa * x / 2 + bb * y / 2;
    }
    cout << res << ln;
}