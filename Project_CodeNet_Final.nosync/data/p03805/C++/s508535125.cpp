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

ll fact(ll n){
    if(n ==1) return 1;
    return n * fact(n-1);
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    // グラフ
    Graph G(N);

    REP(i, M){
        ll a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<ll> nums(N);
    REP(i, N){
        nums[i] = i;
    }

    ll p = fact(N);

    ll ans = 0;
    REP(i, p){
        if(nums[0] != 0) continue; 
        bool flag = true;
        REP(j, N-1){
            // cout << nums[j];
            bool check = false;
            for(auto v: G[nums[j]]){
                if(v == nums[j+1]) check = true;
            }
            if(check == false){
                flag = false;
                break;
            }
        }
        if(flag == true) ans++;
        // cout << endl;
        // 順列の遷移処理
        next_permutation(nums.begin(), nums.end());
    }
    cout << ans << endl;
    return 0;
}