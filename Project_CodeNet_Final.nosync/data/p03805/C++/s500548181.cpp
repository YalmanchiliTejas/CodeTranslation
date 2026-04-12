#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int N;
int ans = 0;
vector<vector<int>> to;
void dfs(int vertex, vector<bool> seen, set<int> vertexes){
    if (seen[vertex]) return;
    if (vertexes.size() == N-1){
        ans++;
        return;
    }
    seen[vertex] = true;
    vertexes.insert(vertex);
    for (auto next_vertex : to[vertex]){
        dfs(next_vertex, seen, vertexes);
    }
}

int main(){
    int M; cin >> N >> M;
    //vector<vector<int>> to(N);
    to.assign(N, vector<int>());
    rep(i,M){
        int a, b; cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    dfs(0, vector<bool>(N, false), set<int>());

    cout << ans << endl;
}