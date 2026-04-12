#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    if(n == 1){
        cout << x << endl;
        return 0;
    }
    set<ll> memo;
    vector<ll> ans(m+1000,0);
    ans[0] = x;
    ll now = x;
    memo.insert(x);
    ll check = 0,endnum = 0;;
    ll state = 0;
    // ??
    if(n < 300000){
        ll ansk = x;
        rep(i,n-1){
            x *= x;
            x %= m;
            ansk += x;
        }
        cout << ansk << endl;
        return 0;
    }


    rep(i,1LL,min(m+1,n)){
        now *= now;
        now %= m;
        ans[i] = now;
        if(memo.find(now) == memo.end()){
            // 存在しない
            memo.insert(now);
        }else{
            state = 1;
            check = now;
            endnum = i - 1;
            break;
        }
    }
    // ここより下
    if(state == 0){
        ll anss = 0;
        rep(i,n) {
            anss += ans[i];
        }
        cout << anss << endl;
        return 0;
    }
    // ここより上
    ll start = 0;
    rep(i,m){
        if(ans[i] == check){
            start = i;
            break;
        }
    }
    // ここより上
    ll res = 0;
    ll sum = 0;
    rep(i,start){
        res += ans[i];
    }
    n -= start;
    
    rep(i,endnum - start + 1){
        sum += ans[i + start];
    }
    if(start > endnum){
        cout << "a" << endl;
        return 0;
    }

    ll div = n/(endnum - start + 1);
    res += sum * div;

    rep(i,n % div){
        res += ans[i+start];
    }
    cout << res << endl;
}