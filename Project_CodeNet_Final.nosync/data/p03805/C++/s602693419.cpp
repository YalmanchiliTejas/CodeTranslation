#include <bits/stdc++.h>
using namespace std;

const int nmax=8;
bool graph[nmax][nmax];

int pass(int v,int N,bool checked[nmax]){//頂点vに至るまでの経路の個数
    //以下すべて到達済みの時の処理
    bool allchecked =true;
    for(int i=0;i<N;i++){
        if(checked[i]==false) allchecked=false; 
    }
    if(allchecked) return 1;
    //処理終わり
    //以下到達済みでない場合
    int ret=0;
    for(int i=0;i<N;i++){
        if(graph[v][i]==false) continue;//頂点vの隣接する頂点に関し検索する
        if(checked[i]) continue;//調べた頂点が到達済みならその頂点をスキップする
        checked[i]=true;//到達済みにする
        ret += pass(i,N,checked);
        checked[i]=false;
    }
    return ret;
}
int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1]=graph[b-1][a-1]=true;
    }
   bool checked[nmax];
   for(int i=0;i<N;i++) checked[i]=false;
   checked[0]=true;
   cout << pass(0,N,checked) << endl;
}
