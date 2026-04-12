/*
 * @Author       : nonameless
 * @Date         : 2020-09-19 20:36:30
 * @LastEditors  : nonameless
 * @LastEditTime : 2020-09-19 21:26:22
 */
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sz(x) (int)x.size()
#define toStr(name) (#name)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const double eps = 1e-6;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll LNF  = 0x3f3f3f3f3f3f3f3f;
inline int gcd(int a, int b) { return b ? gcd(b,a % b):a;}
inline ll  gcd(ll  a, ll  b) { return b ? gcd(b,a % b):a;}
inline int lcm(int a, int b) { return a * b / gcd(a, b); }

template<class T>
inline void read(T &x){
    x = 0;
    int f = 1;
    char c = getchar();
    while(c < '0' || c > '9')   { if(c == '-') f = -1;  c = getchar(); }
    while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    x = x * f;
}

template<class T>
inline void out(string a, T x){ cout << a << " = " << x << endl; }


int main(){

    ll n, x, m, a;
    cin >> n >> x >> m;
    vector<ll> vec;
    map<ll, int> mp;
    ll idx = n;
    ll ans = 0;
    a = x;
    int yy = n;
    for(int i = 1; i <= n; i ++){
        yy = i;
        if(mp[a]) { idx = mp[a] - 1; break; }
        mp[a] = i;
        ans += a;
        vec.pb(a);
        a = a * a  % m;
    }
    vector<ll> vec2;
    for(int i = 0; i < sz(vec); i ++) if(i >= idx) vec2.pb(vec[i]);
    ll cnt = n - yy + 1;
    ll sum = 0;
    for(auto it : vec2) sum += it;
    if(sz(vec2)){
        ans += cnt / sz(vec2) * sum;
        for(int i = 0; i < cnt % sz(vec2); i ++) ans += vec2[i];
    } 
    cout << ans << endl;
    
    return 0;
}
