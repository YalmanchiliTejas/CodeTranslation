#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout <<"DEBUG"<<" "<< #x << ":" << x << '\n'

// n回繰り返し
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
#define rep1(i,n) for(int i = 1; i <= ((int)(n)); i++) // 1-indexed昇順
#define rrep(i,n) for(int i = ((int)(n)-1); i >= 0; i--)  // 0-indexed降順
#define rrep1(i,n) for(int i = ((int)(n)); i >= 1; i--)   // 1-indexed降順
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vii;  // 2次元配列
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> PII;

template<typename T>
using vec = vector<T>;
template<class T>
using maxheap = std::priority_queue<T>;
template<class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T,class U> inline bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U> inline bool chmin(T &a, const U &b){if(a>b){a=b;return 1;}return 0;}

const ld Pi = std::acos(-1.0L);
const ll infll = (1LL<<62)-1;
const int inf = (1<<30)-1;
const int mod = 1000000007;
// const int mod = 998244353;

ll n, x;
/*FUNCs=================================================*/
ll dp[51];
ll dp2[51];
ll rec_calc_range(ll n) {
    if(dp[n]!=0) return dp[n];
    if(n==1) return 5;
    ll ret = 1 + rec_calc_range(n-1) + 1 + rec_calc_range(n-1) + 1;
    return dp[n] = ret;
}
ll rec(ll n) {
    if(dp2[n]!=0) return dp2[n];
    if(n==0) return dp2[n] = 1;
    return dp2[n] = rec(n-1) + 1 + rec(n-1);
}
ll recursive(ll n, ll L, ll R) {
    if(x<L) return 0;
    else if(L<=x && x<=R) return recursive(n-1, L+1, (R+L)/2-1) + ((L+R)/2<=x?1:0) + recursive(n-1, (R+L)/2+1, R-1);
    else if(R<x) return dp2[n];
}

/*MAIN==================================================*/
signed main(){
    int START_TIME = clock();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化
    // cout << fixed << setprecision(15);

    cin >> n >> x;
    ll range = rec_calc_range(n);
    ignore = rec(n);
    ll ans = recursive(n, 1, range);

//    for(int i = 0; i < 51; ++i) debug(dp2[i]);

    cout << ans << '\n';
//    debug(range);

    // printf("ExecutionTime: %d /ms\n",1000*(int)((clock()-START_TIME)/CLOCKS_PER_SEC));
}