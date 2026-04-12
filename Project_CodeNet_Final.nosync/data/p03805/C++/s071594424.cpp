#include <iostream>
#include <vector>
using namespace std;

const int nmax=8;
vector<vector<bool>> graph(nmax, vector<bool>(nmax));//隣接グラフ
vector<bool> visited(nmax);//訪問済み判定
int N, M;

int dfs(int v){

    bool all_visited=true;//すべて訪問されたか否か（初期設定はture)

    for(int i=0;i<N;++i){//ひとつでも未訪問のものがあったらfalse
        if(visited.at(i)==false) all_visited=false;
    }
    if(all_visited) return 1;//すべて訪問済みだったら

    int ret=0;//進む場所がなかったら0を返す

    for(int i=0;i<N;++i){
        if(graph.at(v).at(i)==false || visited.at(i)==true) continue;//vとiが隣接していなかったら or iが訪問済みだったら 飛ばす
        visited.at(i)=true;//訪問済み
        ret+=dfs(i);
        visited.at(i)=false;//訪問済みの解除
    }

    return ret;
}

int main(void){
    cin >> N >> M;

    for(int i=0;i<M;++i){//隣接グラフに0オリジン(-1)で値を入れる
        int A,B;
        cin >> A >> B;
        graph.at(A-1).at(B-1)=graph.at(B-1).at(A-1)=true;
    }

    for(int i=0;i<N;++i){//すべて未訪問
        visited.at(i)=false;
    }

    visited.at(0)=true;
    cout << dfs(0) << endl;
    return 0;
}