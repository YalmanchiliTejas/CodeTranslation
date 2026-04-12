//////// Sum_of_product_of_pairs 
// https://atcoder.jp/contests/abc177/tasks/abc177_c
// date: 2020-08-29T21:00:28.778617
// memo: 
    
//<editor-fold desc="my macro">

#include<bits/stdc++.h>
#ifdef LOCAL
    #include<my/dump.h>
#else
    #define dump(...) 42 
    #define dumpi(x) 42 
#endif

typedef long long ll;
using namespace std;

#define repe(x, a) for(auto& (x) : (a))
#define _overload3(_1, _2, _3, name, ...) name
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rep3(i, a, b) for(ll i=a, i##_len=(b);i<i##_len;i++)
#define _rep2(i, n) _rep3(i,0,n)
#define repd(...) _overload3(__VA_ARGS__,_repd3,_repd2,)(__VA_ARGS__)
#define _repd3(i, a, b) for(ll i=b-1, i##_len=(a);i>=i##_len;i--)
#define _repd2(i, n) _repd3(i,0,n)
#define loop(...) _overload3(__VA_ARGS__,,_loop2,_loop1)(__VA_ARGS__)
#define _loop2(i, a) for(ll i=a;; i++)
#define _loop1(i) _loop2(i,0)

#define all(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

#define F first
#define S second
#define vec vector
#define umap unordered_map
#define uset unordered_set

ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define inrange(x,start,stop) ((start) <= (x) && (x) < (stop))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template <typename Cont, typename Func>
Cont fmap(const Cont &container, Func functor) {
    Cont result(container.size());
    std::transform(container.begin(), container.end(), result.begin(), functor);// [](int x){return x * 2;}
    return result;
}
template <typename Cont, typename Pred>
Cont filter(const Cont &container, Pred predicate) {
    Cont result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), predicate);// [](int x){return x == 2;}
    return result;
}   

template<typename T, typename ...Args>
void ci(T& first, Args&... args) {
    ((cin >> first), ..., (cin >> args)); //C++17
}

template<char Sep, typename T, typename ...Args>
void print_seq(const T& first, const Args&... args) {
    ((cout << first), ..., (cout << Sep << args)); //C++17
}

void co(){ cout << endl; }
template<typename... Words>
void co(Words... words) {
    print_seq<' '>(words...);
    cout << endl;
}
#define coi(x) cout<<(x)<<" "

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define sankou(n,a,b) cout << ((n) ? (a) : (b) ) << endl

#define asrt(expr...) assert((expr))
//</editor-fold>

#define INF 1e19
#define MOD 1000000007
#define MAXR 1e5

int solve() {
    ll N;
    ci(N);
    vec<ll> v;
    rep(i,N) {
        ll buf;
        ci(buf);
        v.push_back(buf);
    }
    dump(N,MOD);
    dump(v);

    ll sum_a = 0;
    ll sum_d = 0;
//    bool overflow = false;
    rep(i,N) {
        sum_a += v[i];
//        if (sum_a >= MOD) overflow = true;
        sum_a = fmod(sum_a , MOD*2);

        sum_d += fmod(v[i] * v[i], MOD*2);
        sum_d = fmod(sum_d , MOD*2);
    }

    dump(sum_a); //mod MOD*2
    dump(sum_d); //mod MOD*2

    ll ans = (sum_a * sum_a) - sum_d; // MOD^2*4 ~ -MOD*2
    if (ans < 0) ans += MOD*2; // MOD^2*4 ~ 0
    dump(ans);
    ans /= 2; // MOD^2*2
    ans = fmod(ans , MOD);
    co(ans);
    return 0;
}

int solve2(){

    ll N;
    ci(N);
    vec<ll> v;
    rep(i,N) {
        ll buf;
        ci(buf);
        v.push_back(buf);
    }
    dump(N,MOD);
    dump(v);

    ll sum_a = 0;
    rep(i,N) {
        sum_a += v[i];
        sum_a %= MOD;
    }

    dump(sum_a);

    ll sum = 0;
    rep(i,N) {
        sum_a += MOD - v[i];
        sum_a %= MOD;
        sum += sum_a * v[i]% MOD;
        sum %= MOD;
    }
    co(sum);

    return 0;
}

int main(){
    //入力の高速化用のコード
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    solve2();
    return 0;
}
