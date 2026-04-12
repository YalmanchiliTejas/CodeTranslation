//////// Sequence_Sum 
// https://atcoder.jp/contests/abc179/tasks/abc179_e
// date: 2020-09-19T21:01:38.668111
// memo: 
    
//<editor-fold desc="my macro">

#include <bits/stdc++.h>
#ifdef LOCAL
    #include <my/dump.h>
#else
    #define dump(...) 42 
    #define dumpi(x) 42 
    #define dumpar(...) 42
#endif

typedef long long ll;
using namespace std;

#define repe(x, a) for(auto&& (x) : (a))
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

//digit guide 9876543210987654321
#define LINF           2000000000 //2*10^9
#define INF   9000000000000000000 //9*10^18
#define MOD            1000000007 //1*10^9 + 7
#define MAXR               100010
//digit guide 9876543210987654321

void solve() {
    ll N,X,M;
    ci(N,X,M);

    dump(N,X,M);

    ll a[MAXR];
    ll sums[MAXR];
    uset<ll> hist;
    ll indices[MAXR];

    a[0] = X;
    sums[0] = X;
    hist.insert(X);
    indices[X] = 0; // Xは0番目。ある数がN番目に出現したか。

    ll buf=X;
    ll counter=1;
    ll next;

    ll loop_n=0;
    ll start_index=0;
    ll last;
    rep(i,1,N) {
        next = (buf * buf) % M;
        if (hist.count(next)) {
            start_index = indices[next];
            loop_n = i - start_index;
            break;
        }
        hist.insert(next);
        a[counter] = next;
        indices[next] = counter; //
        counter++;
        last=i;
        buf = next;
    }
    
    if(loop_n) {
        ll head = 0;
        rep(i,0,start_index) head += a[i];

        ll tail = 0;
        ll tail_index = (N - start_index) % loop_n;
        rep(i,start_index,start_index+tail_index) tail += a[i];

        ll loop_sum = 0;
        rep(i,start_index,start_index+loop_n) loop_sum += a[i];
        loop_sum *= (floor((N-start_index) / loop_n));

        co(head+tail+loop_sum);

        dump(start_index,loop_n);

    } else {
        ll ans = 0;
        rep(i,N) ans += a[i];
        co(ans);
    }
}

int main(){
    //入力の高速化用のコード
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    solve();
    return 0;
}
