#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
#define int int_fast64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;

inline int updiv(int a,int b){ return (a + b - 1) / b; }
 
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios_base::fixed);
    cout.precision(12);

    int n, m;
    cin >> n >> m;

    vector<vector<bool> > path(n, vector<bool>(n));

    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        path[a][b] = true;
        path[b][a] = true;
    }

    vector<int> p(n-1);
    iota(all(p), 1);

    int res = 0;

    do{
        int now = 0;
        rep(i,n-1){
            if(path[now][p[i]]){
                now = p[i];
            }else{
                goto ng;
            }
        }
        ++res;
        ng:;
    }while(next_permutation(p.begin(), p.end()));

    cout << res << '\n';

    return (0);
}