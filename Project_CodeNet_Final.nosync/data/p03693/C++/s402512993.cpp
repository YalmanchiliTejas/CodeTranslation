#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define each(e,v) for(auto&& e:(v))
#define all(v) begin(v),end(v)
#define DUMP(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<": "<<(x)<<" (L"<<__LINE__<<")"<<endl
using namespace std;
using vint = vector<int>;
using vdouble = vector<double>;
using vstring = vector<string>;
using ll = long long;
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int main() {
    int r, g, b; cin >> r >> g >> b;
    int c = 100 * r + 10 * g + b;
    if(c % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
