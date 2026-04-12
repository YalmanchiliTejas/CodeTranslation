#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

constexpr const int INT_INF=0x3f3f3f3f; // 1061109567
constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f; // 4557430888798830399
constexpr const double D_INF=numeric_limits<double>::infinity();
constexpr const ld LD_INF=numeric_limits<ld>::infinity();
constexpr const double EPS=1e-9;

template<typename T>constexpr bool flt(const T&x,const T&y){return x<y-EPS;}
template<typename T>constexpr bool fgt(const T&x,const T&y){return x>y+EPS;}
template<typename T>constexpr bool feq(const T&x,const T&y){return abs(x-y)<=EPS;}
template<typename T>constexpr bool in(const T&v,const T&lo,const T&hi){return!(v<lo||hi<v);}
template<typename T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}
template<typename T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<typename T,typename...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<typename T,typename...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<typename T,typename...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}
template<typename T,typename...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<typename T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}
template<typename T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<typename T,typename...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<typename T,typename...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
#define clamp(...) _clamp(__VA_ARGS__)
#define make_unique _make_unique
#define make_shared _make_shared

// INT
#define GCD(a, b) __gcd(a, b)
template <typename T> T LCM(T a, T b) {return a / GCD(a, b) * b;}
template <typename T> T EXTGCD(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {d=EXTGCD(b,a%b,y,x);y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}
template <typename T> bool is_prime(T a) {
    for(int i=2;i*i<=a;i++)if(a%i==0)return 1;
    return 0;
}

// MOD
const ll MOD = 1000000000 + 7;
#define add(a, b) ((a % MOD) + (b % MOD)) % MOD
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define sub(a, b) ((a % MOD) + MOD - (b % MOD)) % MOD
template <typename T> T mod_inverse(T a, T mod, bool prime){ // if mod is prime, "prime" is true.
    if(prime){
    T tmp=mod-2,now=a,res=1;while(tmp){if(tmp&1)res=mul(res,now);now=mul(now,now);tmp>>=1;}
    return res;
    }else{T x,y;EXTGCD(a,mod,x,y);return (mod+x%mod)%mod;}
}
#define divide(a, b) ((a % MOD) * (mod_inverse(b, MOD, true))) % MOD

// llのとき、数値の最後に"L"を付ける癖をつけよう.

//
//
//  　　┓　　　┏
//  　＊┗┓　┏┛
//  　　　┫　┣　＊
//  　┏┳┻━┻┳┓
//  　┗┫　　　┣┛
//  ＊　┣　　━┃　＊        Merry Christmas!!
//  　┏┛　　〃┃
//  　┃●　　　┣━┳┓
//  　┗┻┳━━┛　┣┛
//  　＊　┃┏┓┣┓┃
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

class union_find{
public:
    explicit union_find(int _n):n(_n){
        par.resize(static_cast<unsigned long>(_n));
        rank.resize(static_cast<unsigned long>(_n));
        sizes.resize(static_cast<unsigned long>(_n));
        for(int i=0;i<_n;i++){
            par[i]=i;
            rank[i]=0;
            sizes[i]=1;
        }
    }

    //親ノードを見つけます
    int find(int a){
        if(par[a]==a)return a;
        return par[a]=find(par[a]);
    }

    //aとbが同じグループかの判定
    bool same(int a,int b){
        return find(a)==find(b);
    }

    //aとbを同じグループにします
    void unite(int a,int b){
        link(find(a),find(b));
    }

    //aが属するグループの要素数を求めます
    int size(int a){
        return sizes[find(a)];
    }

    //全体がどのグループに属しているかがわかります
    void view(){
        for(int i=0;i<n;i++){
            cout<<" par"<<"["<<i<<"]="<<par[i]<<((i==n-1)?"\n":",");
        }
        for(int i=0;i<n;i++){
            cout<<"size"<<"["<<i<<"]="<<sizes[i]<<((i==n-1)?"\n":",");
        }
        cout<<endl;
    }

private:
    void link(int a,int b){
        if(same(a,b))return;
        if(rank[a]>rank[b]){
            par[b]=a;
            sizes[a]+=sizes[b];
            sizes[b]=0;
        }else{
            par[a]=b;
            if(rank[a]==rank[b])rank[b]++;
            sizes[b]+=sizes[a];
            sizes[a]=0;
        }
    }
    int n;
    vector<int> par;
    vector<int> rank;
    vector<int> sizes;
};

int n;
string s;
vector<tuple<int, int, int>>v, v2;
vector<tuple<int, int, int>> edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    FILE *stream1;
    //FILE *stream2;
    stream1 = freopen("/home/aim_cpo/ドキュメント/competitive/CLionProject/competitive/in.txt", "r", stdin);
    //stream2 = freopen("out.txt", "w", stdout);
    if (stream1 == NULL) return 0;
    //if (stream2 == NULL) return 0;
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back(mt(x, y, i));
        v2.push_back(mt(y, x, i));
    }
    sort(all(v));
    sort(all(v2));
    for (int i = 0; i < (int)v.size() - 1; i++) {
        int nowx, nowy, now;
        tie(nowx, nowy, now) = v[i];
        int nextx, nexty, next;
        tie(nextx, nexty, next) = v[i + 1];
        edge.push_back(mt(_min(abs(nowx - nextx), abs(nowy - nexty)), now, next));
    }
    for (int i = 0; i < (int)v2.size() - 1; i++) {
        int nowx, nowy, now;
        tie(nowx, nowy, now) = v2[i];
        int nextx, nexty, next;
        tie(nextx, nexty, next) = v2[i + 1];
        edge.push_back(mt(_min(abs(nowx - nextx), abs(nowy - nexty)), now, next));
    }
    sort(all(edge));
    union_find uf(n);
    ll ans = 0L;
    for (auto i:edge) {
        int cost, from, to;
        tie(cost, from, to) = i;
        if (!uf.same(from, to)) {
            ans += cost;
            uf.unite(from, to);
        }
    }
    cout << ans << endl;
#ifdef  LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
    return 0;
}