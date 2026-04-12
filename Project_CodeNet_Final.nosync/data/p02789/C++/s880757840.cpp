#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
 
// #include <iostream> // cout, endl, cin
// #include <string> // string, to_string, stoi
// #include <vector> // vector
// #include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
// #include <utility> // pair, make_pair
// #include <tuple> // tuple, make_tuple
// #include <cstdint> // int64_t, int*_t
// #include <cstdio> // printf
// #include <map> // map
// #include <queue> // queue, priority_queue
// #include <set> // set
// #include <stack> // stack
// #include <deque> // deque
// #include <unordered_map> // unordered_map
// #include <unordered_set> // unordered_set
// #include <bitset> // bitset
// #include <climits>
// #include <cmath>
// #include <iomanip>
// #include <functional>
// #include <numeric>
// #include <random>
 
using namespace std;
    
#define int long long
#define pb push_back
#define eb emplace_back
// #define F first
// #define S second-l
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define UNIQUE(a) sort(all(a)), a.erase(unique(all(a)), a.end())
 
template<typename T> using pq = priority_queue<T,vector<T>,greater<T>>; 
using ll = long long;
ll INF = LLONG_MAX / 10 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;

double pi = 3.141592653589793238;
    
class fact {
public:
    int fmod = 1e9+7;
    vector<int> fac, finv, inv;
    fact (int n, int Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<int>(n + 1, 0);
        finv = vector<int>(n + 1, 0);
        inv = vector<int>(n + 1, 0);
        fac[0] = 1; for (int i = 1; i < n + 1; i++) fac[i] = fac[i-1] * i % fmod;
        for (int i = 0;i < n + 1;i++) finv[i] = fact::POW(fac[i], fmod-2);
        for (int i = 0;i < n + 1;i++) inv[i] = POW(i, fmod-2);
    }
    ll nCr(ll n, ll r) {if(n < r) return 0; return (fac[n] * finv[r] % fmod) * finv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
    inline int operator [] (int i) {return fac[i];}
};
    
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b);}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((double)abs(x1-x2)*(double)abs(x1-x2)+(double)abs(y1-y2)*(double)abs(y1-y2));
}
int ceili(int x, int y) {
    if (x % y == 0) return x / y;
    else return x / y + 1;
}
 
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long mul(long long a, long long b, long long mod) {
    a %= mod, b %= mod;
    long long keta[20] = {};
    long long c = b;
    long long now = 0;
    while (c != 0ll) {
        keta[now] = c % 10; c /= 10; now++;
    }
    long long res = 0;
    for (int i = 19; i >= 0; --i) {
        res *= 10; res %= mod;
        res += keta[i] * a % mod;
    }
    return res % mod;
}

ll POW2(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = mul(a, c, mod);}a = mul(a, a, mod)%mod; b >>= 1;}return c;}

template<typename Monoid>
class SegTree {

//半開区間!!!!!!!!!!!!!!!
public:
    int p = 2;
    vector<Monoid> node;
    using Func = function<Monoid(Monoid,Monoid)>;
    Func pick; Monoid init;//操作と単位元

    SegTree(vector<Monoid> A, string type, Monoid m) {
        if (type == "min") {
            pick = [](Monoid a, Monoid b){return min(a,b);};
        } else if (type == "max") {
            pick = [](Monoid a, Monoid b){return max(a,b);};
        } else if (type == "sum") {
            pick = [](Monoid a, Monoid b){return a + b;};
        }

        init = m;
        while (A.size() > p) p *= 2;
        node = vector<Monoid>(2*p-1,init);

        for (int i = 0;i < A.size();i++) {
            node[p-1+i] = A[i];
        }

        for (int i = p - 2;i >= 0;i--) {
            node[i] = pick(node[i*2+1],node[i*2+2]);
        }
    }

    SegTree(vector<Monoid> A, Func f, Monoid m) {
        pick = f; init = m;
        while (A.size() > p) p *= 2;
        node = vector<Monoid>(2*p-1,init);

        for (int i = 0;i < A.size();i++) {
            node[p-1+i] = A[i];
        }

        for (int i = p - 2;i >= 0;i--) {
            node[i] = pick(node[i*2+1],node[i*2+2]);
        }
    }

    //1点更新
    void update(int i, Monoid v) {
        for (node[(i+=p)-1] = v; i >>= 1;) {
            node[i-1] = pick(node[i*2-1], node[i*2]);
        }
    }

    //1点加算
    void add(int i, Monoid v) {
        update(i, node[p-1+i] + v);
    }
 
    Monoid getval(int start,int end,int k = 0,int l = 0,int r = -1) {
        if (r < 0) r = p;
        if (r <= start || end <= l) {return init;}
        if (start <= l && r <= end) {return node[k];}
        Monoid L,R;
        L = getval(start,end,k*2+1,l,(l+r)/2);
        R = getval(start,end,k*2+2,(l+r)/2,r);
        return {pick(L,R)};
    }

    inline Monoid operator [] (int i) {
        return node[i+p-1];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    YesNo(n == m);
}
 
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
