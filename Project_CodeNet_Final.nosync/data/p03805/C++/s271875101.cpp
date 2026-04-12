#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <iomanip>
using namespace std;
#define MAXSIZE 100005
#define MAXL 100
#define MOD_CONST 1000000007
typedef long long int lli;

void dfs(int vertex, int &ans, const vector<vector<int>> &adj_mat, vector<int> &vertex_vec);

bool has_visited_every_vertex(vector<int> &vertex_vec);

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_mat(n, vector<int> (n, 0));
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj_mat[a][b] = adj_mat[b][a] = 1;
    }

    vector<int> vertex_vec(n, 0);
    int ans = 0;
    dfs(0, ans, adj_mat, vertex_vec);
    cout << ans << endl;
}

void dfs(int vertex, int &ans, const vector<vector<int>> &adj_mat, vector<int> &vertex_vec){
    /* 既に訪問済みの頂点である場合 */
    if(vertex_vec[vertex] == 1){
        return;
    }

    /* 現在いる頂点に訪問済みの印をつける */
    vertex_vec[vertex] = 1;

    /* すべての頂点を訪問済みである場合 */
    if(has_visited_every_vertex(vertex_vec)){
        ans++;
        vertex_vec[vertex] = 0;
        return;
    }

    /* 現在いる頂点に隣接しているそれぞれの頂点に対して再帰呼び出し */
    for(size_t i = 0; i < adj_mat[vertex].size(); ++i){
        if(adj_mat[vertex][i] == 1){
            dfs(i, ans, adj_mat, vertex_vec);
        }
    }

    /* 現在いる頂点から訪問済みの印を消す */
    vertex_vec[vertex] = 0;
}

bool has_visited_every_vertex(vector<int> &vertex_vec){
    for(size_t i = 0; i < vertex_vec.size(); ++i){
        if(vertex_vec[i] == 0){
            return false;
        }
    }
    return true;
}