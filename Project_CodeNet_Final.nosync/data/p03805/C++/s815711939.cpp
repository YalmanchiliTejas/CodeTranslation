#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(int i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(int i = (a); i > (b); --i)
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)

#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない
#define N 100
#define INFTY (1 << 21) //10^21
bool M[N][N];//隣接行列
int color[N];

//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
static const int NIL = -1;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector>	DVector;
int n;

//配列の表示
void printArray(int array[], int n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

bool visited[N];

int dfs_visit(int u){
    
    visited[u] = true;
    
    bool all_visited = true;
    rep(i, n){
        if(!visited[i]) all_visited = false;
    }
    if(all_visited) return 1;
    
    int res = 0;
    
    rep(v, n){
        if(M[u][v] == false)    continue;
        if(visited[v] == false){
            
            res = res + dfs_visit(v);
            visited[v] = false;
        }
    }
    
    return res;
}

int dfs(){
    rep(i, n)   visited[i] = false;
    
    int res = dfs_visit(0);
    return res;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        M[a - 1][b - 1] = M[b - 1][a - 1] = true;
    }
    
    int res = dfs();
    cout << res << endl;
}