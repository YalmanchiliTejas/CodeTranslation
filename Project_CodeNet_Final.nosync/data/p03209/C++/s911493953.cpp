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

vector<ll> B;
vector<ll> PA;

ll func(ll k, ll X){
    if(k == 0) return 1;
    else{
        if(X == 1) return 0;
        else if((X >= 2) && (X <= B[k-1] + 1)){
            return func(k-1, X-1);
        }
        else if(X == B[k-1] + 2){
            return PA[k-1] + 1;
        }
        else if((X >= B[k-1] +3) && (X <= 2*B[k-1] + 2)){
            return func(k-1, X-B[k-1]-2) + PA[k-1] + 1;
        }
        else if(X == 2*B[k-1] + 3){
            return PA[k];
        }
    }
    return 0;
}

int main()
{
    cout << fixed << setprecision(15);

    ll N, X;
    cin >> N >> X;

    B.assign(N+1, 0);
    PA.assign(N+1, 0);

    B[0] = 1;
    PA[0] = 1;

    REP(i, N){
        B[i+1] = B[i]*2 + 3;
        PA[i+1] = PA[i]*2 + 1;
    }

    // func(N, X) Nレベルバーガーの
    cout << func(N, X) << endl;
    return 0;
}