#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

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

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    REP(i, H){
        REP(j, W){
            cin >> a[i][j];
        }
    }

    vector<bool> HC(H, false);
    vector<bool> WC(W, false);

    REP(i, H){
        REP(j, W){
            if(a[i][j] == '#'){
                HC[i] = true;
                WC[j] = true;
            }
        }
    }

    REP(i, H){
        REP(j, W){
            if(HC[i] && WC[j]){
                cout << a[i][j];
            }
        }
        if(HC[i]) cout << endl;
    }
    return 0;
}