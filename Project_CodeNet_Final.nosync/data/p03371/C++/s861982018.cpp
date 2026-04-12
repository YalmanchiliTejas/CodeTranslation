
/* 実行時間1s制限の場合10^6 1,000,000 : 余裕をもって間に合う10^7
  10,000,000 : おそらく間に合う10^8 100,000,000 : 非常にシンプルな処理
  でないと厳しい
 */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;

typedef long long ll; // long longはデータモデル(LLP64, LP64, ...)によらず64bit.
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
} // Greatest Common Divisor ユークリッドの互除法（aが長辺）
vector<pair<ll, int>> factorize(ll n) { // a,bの公約数 = GCD(a, b)の約数
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; i++) { // √nまで探せばよい
        if(n % i)
            continue;
        res.emplace_back(i, 0); // 割り切れたら
        while(n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1)
        res.emplace_back(n, 1); // この時点で1でなかったら、残りは素数.
    return res;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
} // Least Commont Multiple オーバーフローしないように先に割る
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

const ll INF = LONG_MAX;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

// https://qiita.com/drken/items/4a7869c5e304883f539b#3-3-dfs-%E3%81%AE%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%AE%9F%E8%A3%85
/*
using Graph = vector<vector<int>>;
vector<bool> seen;
// 初期化方法 seen.assign(N, false); // 全頂点を「未訪問」に初期化
void dfs(const Graph &g, int v) {
    seen[v] = true;
    for(auto next_v : g[v]) {
        if(seen[next_v])
            continue;
        dfs(g, next_v);
    }
}
*/
// ***
// 01 - BSF
// ***
// ex.
//    Edge edge[9];
//    vector<int> dist(9);
//    addEdge(true, edge, 0, 1, 0);
//    addEdge(true, edge, 0, 7, 1);
//    ...
//    int src = 0;  // source node
//    zeroOneBFS(edge, dist ,src);

int main() {

#ifdef LOCAL
    // 以降 cin の入力元が 'xxx.txt' になる
    std::ifstream in("code.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    int num_a = 0;
    int num_b = 0;
    int num_c = 0;
    if((a + b) < c * 2) {
        num_a = x;
        num_b = y;
    } else {
        num_c = min(x, y) * 2;
        if(x < y) {
            if(b < 2 * c) {
                num_b = y - num_c / 2;
            } else {
                num_c += (y - num_c / 2) * 2;
            }
        } else {
            if(a < 2 * c) {
                num_a = x - num_c / 2;
            } else {
                num_c += (x - num_c / 2) * 2;
            }
        }
    }

    cout << num_a * a + num_b * b + num_c * c;

    return 0;
}

/*
  - 最大値
    long long 9,223,372,036,854,775,807 < 9.223.. * 10^18
  - 1e9 : 10^9
  - container一般
    - 合計
      accumulate(a.begin(), a.end(), 0LL)  0LLはオーバーフロー用.
  数値は合計に履かせる下駄.
  - vector
    vector<int> A(N, 0); // 0で初期化(省略可)
    vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));  //
  2次元配列初期化
    - loop
      for  (int i = 0; i < A.size(); i++) {}
      for  (int elem : A) {}
    - sort
      std::sort(v.begin(), v.end());  // 昇順
      std::sort(v.begin(), v.end(), std::greater<int>()); //降順
      - vector<vector<int>> cnt(h, vector<int>(w))
    - sort(struct)
        struct st_t {
            string name;
            int p;
            bool operator<(const st_t& another) const {
                if (name == another.name)
                {
                    return p > another.p;
                }
                return name < another.name;
            }
        };
        vector<st_t> st(n);
        sort(st.begin(), st.end());
  - pair
    - pairのソートの定義 : firstが優先的に比較。同じだったらsecond。
    - pair<pair<string,int>,int> p[110];
      std::sort(p,p+a);
        こうすると、first.first -> first.second -> secondの順にソートされる
    - sort
      - sort(a.begin(), cb.end(), greater<pair<int, int>>());
  - map
    - for (auto x : map) {}  // x.first:key  x.second:value.
  - priority_queue<int> q;
    - q.top()に最大値が入っている
  - string
    - loop
      for (char& c : s) {}
 */
/*
    // エラトステネスのふるい
    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }
*/

#if 0
struct node {
    int to, weight;
};
using Edge = vector<node>;
void addEdge(bool directed, Edge *edges, int u, int v, int wt) {
    edges[u].push_back({v, wt});
    if(!directed) {
        edges[v].push_back({u, wt});
    }
}

int pre_node[100000];
void zeroOneBFS(Edge *edges, vector<int> &dist, int src) {
    // Initialize distances from given source
    for(int i = 0; i < dist.size(); i++)
        dist[i] = INT_MAX;
    // double ende queue to do BFS.
    deque<int> Q;
    dist[src] = 0;
    Q.push_back(src);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop_front();

        for(int i = 0; i < edges[v].size(); i++) {
            // checking for the optimal distance
            if(dist[edges[v][i].to] > dist[v] + edges[v][i].weight) {
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
                pre_node[edges[v][i].to] = v;

                // Put 0 weight edges to front and 1 weight
                // edges to back so that vertices are processed
                // in increasing order of weights.
                if(edges[v][i].weight == 0)
                    Q.push_front(edges[v][i].to);
                else
                    Q.push_back(edges[v][i].to);
            }
        }
    }

    // printing the shortest distances
    for(int i = 0; i < dist.size(); i++)
        cout << dist[i] << " ";
}
#endif