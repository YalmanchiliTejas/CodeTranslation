#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

#define chmax(x,y) x = max(x,y)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll dp[200005][4];

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<ll> A(N);
    REP(i, N){
        cin >> A[i];
    }
    
    // 奇数なら2個偶数なら1個入れられる
    ll k = 1 + N%2;

    // dpテーブルの初期化
    REP(i, N+1){
        REP(j, k+1){
            dp[i][j] = -LINF;
        }
    }
    dp[0][0] = 0;

    REP(i,N) {
        REP(j,k+1) {
        chmax(dp[i+1][j+1], dp[i][j]);
        ll now = dp[i][j];
        if ((i+j)%2 == 0) now += A[i];
        chmax(dp[i+1][j], now);
        }
    }
    ll ans = dp[N][k];
    cout << ans << endl;
    return 0;
}