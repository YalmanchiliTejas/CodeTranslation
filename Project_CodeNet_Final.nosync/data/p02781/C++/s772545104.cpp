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

vec<vii> dp;
/*FUNCs=================================================*/


/*MAIN==================================================*/
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化
    cout << fixed << setprecision(15);

    string s; cin >> s;
    int n = s.size();
    int K; cin >> K;
    dp.resize(101, vii(4, vi(2)));
    // i桁までで, 非ゼロをj個使って作れるs以下の数の個数
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(k,2) {
        // nd : 次に見る桁の数字
        int nd = s[i]-'0';
        // 0~9のどれに遷移するか
        rep(d,10) {
            int ni = i +1, nj = j, nk = k;
            if(d != 0) nj++;  // 非ゼロを使った
            if(nj > K) continue;  // 非ゼロはK回までしか使えない
            if(k == 0) {  // そこまでの桁はsと一致(これ以降の桁の数字はsのものを超えない)
                if(d > nd) continue;
                if(d < nd) nk = 1;
            }  // else -> そこまでの桁はsより小さい。(これ以降の桁は自由に選べる)
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << '\n';
}