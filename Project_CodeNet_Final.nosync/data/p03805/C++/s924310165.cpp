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

vector<bool> seen;  // 訪問済みの点
ll ans;
ll N, M;

// BFSのための再帰関数
void dfs(const Graph &G, int v, int counter) {
    if(counter == N-1){
        ans++;
    }
    else{
        for (auto next_v : G[v]) { 
            if (seen[next_v]) continue;
            seen[v] = true;
            dfs(G, next_v, counter+1); // 再帰的に値を追加していく
            seen[v] = false;
        }
    }
}

int main()
{
    cout << fixed << setprecision(15);
    cin >> N >> M;

    // グラフ
    Graph G(N);
    seen.assign(N, false);

    REP(i, M){
        ll a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    ans = 0;

    // 幅優先探索でカウンターを加算
    dfs(G, 0, 0);

    cout << ans << endl;
    return 0;
}