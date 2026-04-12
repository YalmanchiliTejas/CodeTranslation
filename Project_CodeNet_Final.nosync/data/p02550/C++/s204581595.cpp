//header{{{
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) begin(x),end(x)
#define Fixed fixed << setprecision(12)
#define int int_fast64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7;
constexpr int mod2 = 998244353;
 
template <class Func>
class FixPoint : Func {
public:
    explicit constexpr FixPoint(Func&& f) noexcept : Func(forward<Func>(f)) {}
 
    template <class... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return Func::operator()(*this, std::forward<Args>(args)...);
    }
};
 
template <class Func>
static inline constexpr decltype(auto) makeFixPoint(Func&& f) noexcept {
    return FixPoint<Func>{forward<Func>(f)};
}
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
template <class T> using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using Umap = gp_hash_table<K, V>;
using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
 
inline int square(int a){ return a * a;}
inline int updiv(int a,int b){ return (a + b - 1) / b; }
 
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
//}}}


signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios_base::fixed);
    cout.precision(10);

    int n, x, m;
    cin >> n >> x >> m;

    int tmp = x;

    vector<int> cum(1e6);
    cum[1] = x;

    vector<int> f(1e6, -1);

    int l, r, k, len = -1;
    int res = 0;

    for(int i = 2; i <= n; ++i){
        res += tmp;
        int p = tmp * tmp % m; 
        tmp = p;
        if(~f[tmp]){
            l = f[tmp];
            r = i - 1;
            k = n - i + 1;
            len = i - l;
            break;
        }else{
            f[tmp] = i;
        }
        cum[i] = p + cum[i-1];
    }

    if(~len){
        res += k / len * (cum[r] - cum[l-1]);
        k %= len;
        res += cum[l + k - 1] - cum[l-1];
        cout << res << '\n';
    }else{
        cout << res + tmp << '\n';
    }

    return 0;
}