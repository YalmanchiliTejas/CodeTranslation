#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
static const int N = 8;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int NIL = -1;

int n, ans, M[N][N];//nは頂点数、Mは隣接行列
int color[N], d[N], f[N], tt; //color:状態,d:iの発見時刻,f:iの隣接リスト調査完了時刻,tt:時間
int nt[N];//uの隣の頂点をどこまで見たか記録

//u に隣接するvを番号順に取得
int next(int u){
    for(int v = nt[u]; v < n; v++){
//        cout << nt[u] << endl;
        nt[u] = v + 1;//uの隣の頂点をどこまで見たか記録
        if( M[u][v] ) return v;
    }
    nt[u] = 0;
    return NIL;
}

//スタックを用いた深さ優先探索
void dfs_visit(int r){
    for(int i = 0; i < n; i++) nt[i] = 0;

    stack<int> S;//訪問途中の頂点を退避するスタック
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while( !S.empty()){
        int u = S.top();//uが現在訪問中の頂点
        int v = next(u);
//        cout << u << " " << v << endl;
        if(v != NIL){//vがNULLではなかったら
            if(color[v] == WHITE){
                color[v] = GRAY;//訪問したらGRAYに
                d[v] = ++tt;
                S.push(v);
                bool flag = 1;
                for(int i = 0; i < n; i++){
                    if(color[i] != GRAY){
                        flag = 0;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }else{
            S.pop();//訪問完了したらSから退避しましょう
            color[u] = WHITE;//退避した場所は白に戻す
            f[u] = ++tt;
        }
    }
}

void dfs_init(){
    //初期化
    for(int i = 0; i < n; i++){
        color[i] = WHITE;
        nt[i] = 0;
    }
    tt = 0;

    //未訪問のuを始点として深さ優先探索
    dfs_visit(0);
    
}

int main(){
    int m;
    cin >> n >> m;
    int a, b;

    //隣接行列初期化
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            M[i][j] = 0;
        }
    }

    //隣接行列読み込み
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        M[a-1][b-1] = 1;
        M[b-1][a-1] = 1;
    }
    ans = 0;
    dfs_init();

    cout << ans << endl;

    return 0;
}
