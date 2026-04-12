#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 998244353
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    ll n, x, m;
    cin >> n >> x >> m;
    vi id(m, -1);
    vi a;
    int len = 0;
    ll total = 0;
    while(id[x] == -1){
        a.push_back(x);
        id[x] = len;
        len++;
        total += x;
        x = (x*x) % m;
    }

    int roop = len - id[x];
    ll s = 0;
    for(int i = id[x]; i < len; i++) s += a[i];

    ll ans = 0;
    if(n <= len){
        rep(i, n) ans += a[i];
    }else{
        ans += total;
        n -= len;
        ans += s*(n/roop);
        n %= roop;
        rep(i, n) ans += a[id[x] + i];
    }
    cout << ans << endl;
}