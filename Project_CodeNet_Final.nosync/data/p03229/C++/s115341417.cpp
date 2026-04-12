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
    ll N; 
    cin >> N;

    vector<ll> A(N);

    REP(i, N){
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());

    if(N==2){
        cout << abs(A[0]-A[1]) << endl;
        return 0;
    }
    if(N==3){
        cout << max(abs(2*A[2] - A[0] - A[1]), abs(2*A[0] - A[1] - A[2])) << endl;
        return 0;
    }
    if(N==4){
        cout << abs(2*A[3]+A[2]-A[1]-2*A[0]) << endl;
        return 0;
    }

    ll plus = 0;
    ll minus = 0;
    if(N%2 == 0){
        for(ll i=0; i<=N/2-2; i++){
            minus += A[i]*2;
        }
        for(ll i=N/2+1; i<=N-1; i++){
            plus += A[i]*2;
        }
        minus += A[N/2-1];
        plus += A[N/2];
        cout << abs(plus - minus) << endl;
        return 0;
    }
    else{
        plus = 0;
        minus = 0;

        for(ll i=0; i<=(N-1)/2-2; i++){
            minus += A[i]*2;
        }
        for(ll i=(N-1)/2+2; i<=N-1; i++){
            plus += A[i]*2;
        }
    
        ll t1, t2;
        t1 = 2 * A[(N-1)/2+1] - A[(N-1)/2] - A[(N-1)/2-1];
        t2 = A[(N-1)/2+1] + A[(N-1)/2] - 2*A[(N-1)/2-1];

        cout << max(abs(plus-minus+t1), abs(plus-minus+t2)) << endl;
    }
    
    return 0;
}