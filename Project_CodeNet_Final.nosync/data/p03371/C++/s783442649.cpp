#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for(int i=0; i < n; ++i)
#define repe(i, n) for(int i=0; i <= n; ++i)
#define repr(i, n) for(int i=n-1; i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define PI 3.14159265359
#define vi vector<int>
#define vl vector<ll>
using namespace std;
template <class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b<a) {a = b; return 1;} return 0;}
template <class T> using V=vector<T>;
const int INF = 1e9;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,x,y; cin >> a >> b >> c >> x >>y;
    ll res = 0;
    if (x<y) {
        res = min(min(max(x,y)*2*c, x*2*c+abs(x-y)*b), a*x+b*y);
    } else {
        res = min(min(max(x,y)*2*c,y*2*c+abs(x-y)*a), a*x+b*y);
    }
    cout << res << "\n";
}
