#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
/*----------------------------------ここからマクロ----------------------------------*/
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define overload4(_1,_2,_3,_4,name,...) name
/*#define rep1(n) for(int i=0;i<(int)n;++i)
#define rep2(i,n) for(int i=0;i<(int)n;++i)
#define rep3(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define rep4(i,a,b,c) for(int i=(int)a;i<(int)b;i+=(int)c)*/
#define rep1(n) for(ll i=0;i<(ll)n;++i)
#define rep2(i,n) for(ll i=0;i<(ll)n;++i)
#define rep3(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define rep4(i,a,b,c) for(int i=(ll)a;i<(ll)b;i+=(ll)c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#ifdef _DEBUG
#define debug1(a) cerr << #a << ": " << a << "\n"
#define debug2(a,b) cerr << #a << ": " << a << ", " << #b << ": " << b << "\n"
#define debug3(a,b,c) cerr << #a << ": " << a << ", " << #b << ": " << b << ", " << #c << ": " << c << "\n"
#define debug4(a,b,c,d) cerr << #a << ": " << a << ", " << #b << ": " << b << ", " << #c << ": " << c << ", " << #d << ": " << d << "\n"
#define debug(...) overload4(__VA_ARGS__,debug4,debug3,debug2,debug1)(__VA_ARGS__)
#define vecout(a) cerr << #a << ": [";rep(i,a.size()){cerr << a[i];cerr << (i == a.size() - 1 ? "":",");}cerr << "]\n"
#else
#define debug(...)
#define vecout(a)
#endif
#define mp make_pair
//struct doset{doset(int n){cout << fixed << setprecision(n);cerr << fixed << setprecision(n);}};
//struct myset{myset(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}};
void myset(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
void doset(int n){cout << fixed << setprecision(n);}
using ll = long long;
using ld = long double;
using dou = double;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = 3.14159265358;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
typedef pair<ll,ll> P;
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool change(T& a,U& b){if(a > b){swap(a,b);return 1;}return 0;}
//nのm乗をMODで割ったあまりO(logm)
ll modpow(ll n,ll m,ll MOD){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}

ll mypow(ll n,ll m){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n);
        m >>= 1;
        n *= n;
    }
    return res;
}

//素数判定O(sqrt(N))
template<class T>
inline bool isp(T n){
    bool res = true;
    if(n == 1 || n == 0)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}

template<class T = int>
T in(){T x;cin >> x;return x;}

inline bool Yes(bool b){cout << (b ? "Yes\n":"No\n");return b;}
inline bool YES(bool b){cout << (b ? "YES\n":"NO\n");return b;}

/*----------------------------------マクロここまで----------------------------------*/

ll __lcm(ll a,ll b){
    return a / __gcd(a,b) * b;
}

template<class T>
struct UnionFind{
    vector<T> par;
    vector<T> ran;
    vector<T> siz;
    T tree_num;

    UnionFind(T n) : par(n),ran(n,0),siz(n,1),tree_num(n){
        rep(i,n){
            par[i] = i;
        }
    }
    T find(T x){
        if(x == par[x])return x;
        else return par[x] = find(par[x]);
    }
    void unite(T x,T y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        tree_num--;
        if(ran[x] < ran[y]){
            siz[y] += siz[x];
            par[x] = y;
        }
        else{
            siz[x] += siz[y];
            par[y] = x;
            if(ran[x] == ran[y])ran[x]++;
        }
    }
    bool same(T x,T y){
        return find(x) == find(y);
    }
    T get_size(T x){
        return siz[find(x)];
    }
    T renketsu_seibun(){
        return tree_num;
    }
};


typedef pair<ll,pair<ll,ll>> pii;
int main(){
    myset();
    ll N;
    cin >> N;
    UnionFind<ll> UF(N);
    vector<pii> vec(N);
    rep(i,N){
        cin >> vec[i].first >> vec[i].second.first;
        vec[i].second.second = i;
    }
    if(N == 2){
        cout << min(abs(vec[0].first - vec[1].first),abs(vec[0].second.first - vec[1].second.first)) << "\n";
        return 0;
    }
    vector<pii> edge;
    sort(all(vec));
    rep(i,1,N - 1){
        edge.push_back(mp(min(abs(vec[i].first - vec[i - 1].first),abs(vec[i].second.first - vec[i - 1].second.first))
        ,mp(vec[i].second.second,vec[i - 1].second.second)));
        edge.push_back(mp(min(abs(vec[i].first - vec[i + 1].first),abs(vec[i].second.first - vec[i + 1].second.first))
        ,mp(vec[i].second.second,vec[i + 1].second.second)));
    }
    rep(i,N){
        swap(vec[i].first,vec[i].second.first);
    }
    sort(all(vec));
    rep(i,1,N - 1){
        edge.push_back(mp(min(abs(vec[i].first - vec[i - 1].first),abs(vec[i].second.first - vec[i - 1].second.first))
        ,mp(vec[i].second.second,vec[i - 1].second.second)));
        edge.push_back(mp(min(abs(vec[i].first - vec[i + 1].first),abs(vec[i].second.first - vec[i + 1].second.first))
        ,mp(vec[i].second.second,vec[i + 1].second.second)));
    }
    sort(all(edge));
    /*for(auto x : edge){
        cout << x.second.second << "," << x.second.first << ":" << x.first << "\n";
    }*/
    ll ans = 0;
    for(auto x : edge){
        if(!UF.same(x.second.first,x.second.second)){
            UF.unite(x.second.second,x.second.first);
            ans += x.first;
        }
    }
    cout << ans << "\n";
}
