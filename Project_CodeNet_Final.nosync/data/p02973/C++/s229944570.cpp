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
    return a/gcd(a, b) * b;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    multiset<ll> M;

    REP(i, N){
        ll a;
        cin >> a;
        if(i == 0){
            M.insert(a);
            continue;
        }

        // 最小のものと同じかそれよりも小さいときは追加
        if(a <= *M.begin()){
            M.insert(a);
            continue;
        }

        // a以上で最小のものを探す
        auto it = M.lower_bound(a);
        // aより小さいもので一番大きいものを消して塗り替え
        it--;
        M.erase(it);
        M.insert(a);
        
    }

    cout << M.size() << endl;
    return 0;
}