#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

//解説pdfより
const int nmax = 8;
bool graph[nmax][nmax];//セグ木を表すジャグ配列

//再起関数dfs
int dfs(int v, int N, bool visited[nmax]) { //vは今いるnodeの番号-1
    bool allvisited = true;//今のルートがすべてのnodeを網羅したかどうか
    for (int i = 0; N > i; i++) if (visited[i] == false) allvisited = false;//上記を調べる
    if (allvisited) return 1;//網羅したらパターンとしてretに１を足して１階層戻ってみる
    
    int ret = 0;
    for (int i = 0; N > i; ++i) {
        if (graph[v][i] == false) continue;//vからiへ行けるかどうか
        if (visited[i]) continue;//今の階層の前の階層か
        //もしvからiに行けかつ前の階層でなければ
        visited[i] = true;//次の階層に行く前にvisitedをtrueに
        ret += dfs(i, N, visited);//再起
        visited[i] = false;//他の階層を探索するためにvisitedをfalseに戻す
    }

    return ret;//今の合計を戻し一つ前の階層の合計に足し合わせる
    //retに足す数字はallvisitedが成り立った時の1しかないのでretは答えとなる
}

//nodeは常にnodenum-1で保持
int main(void){
    int N, M;
    cin >> N >> M;

    for (int i = 0; M > i; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;//互いの頂点同士行き来できるかどうか
    }

    bool visited[nmax];//訪れたかどうか
    for (int i = 0; N > i; ++i) visited[i] = false;

    visited[0] = true;//１は二度と戻ってこないためtrue
    cout << dfs(0, N, visited) << endl;//探索開始
    return 0;
}