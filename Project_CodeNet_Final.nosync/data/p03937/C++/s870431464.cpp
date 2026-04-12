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
    ll H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));

    REP(i, H){
        REP(j, W){
            cin >> A[i][j];
        }
    }

    // REP(i, H){
    //     REP(j, W){
    //         cout <<  A[i][j];
    //     }
    //     cout << endl;
    // }

    ll tmin = -1;
    REP(i, H){
        ll minj = -1;
        ll maxj = -1;
        ll count = 0;
        REP(j ,W){
            if(A[i][j] == '#'){
                if(minj == -1){
                    minj = j;
                    if(i != 0 && minj != tmin){
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
                maxj = j;
                count++;
            } 
        }
        if(maxj - minj + 1 != count){
            cout << "Impossible" << endl;
            return 0;
        }
        tmin = maxj;
    }
    cout << "Possible" << endl;
    return 0;
}