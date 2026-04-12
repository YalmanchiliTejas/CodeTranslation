#include<bits/stdc++.h>
using namespace std;

//整数からなる配列の総和を求める関数
int sum(vector<int> S){
    int counter = 0;
    for(int i=0; i< S.size(); i++){
        counter = counter + S.at(i);
    }
    return counter;
}

//整数からなる配列に与えられた値が何個あるか数え上げる関数
//頂点の次数を返す関数ともとれる
int search(vector<int> E, int v){
    int counter = 0;
    for(int i=0; i < E.size() ;i++){
        if(E.at(i) == v){
        counter++ ;
    }
  }
   return counter;
}


//グラフGの頂点vに接続している頂点の全体を配列で返す関数
vector<int> connect(vector<int> E, int v){
  int X_size = search(E,v);
  vector<int> X(X_size);
    int counter = 0;
    for(int i=0; i < E.size() ; i= i+2){
        if(E.at(i) == v){
            X.at(counter) = E.at(i+1) ;
            counter++;
        }
    }
    for(int j=1;j < E.size() ; j=j+2){
        if(E.at(j) == v){
            X.at(counter) = E.at(j-1);
            counter++;
        }
    }
    return X;
}


//グラフG=(V,E)と頂点vが与えられたときにVから頂点ｖを削除した後の点集合を返すような関数
//V.at(0)=0として正規化されているものとする
vector<int> vertex_delete(vector<int> V, int v){
    V.at(v) = 0;
    return V;
} 

//グラフG=(V,E)と頂点vが与えられたときにGから頂点vを削除した後の辺集合を返すような関数
//削除したところを０で上書きする
vector<int> edge_delete(vector<int> E, int v){
    for(int i=0; i < E.size() ; i= i+2){
        if(E.at(i) == v){
            E.at(i) = 0;
            E.at(i+1) = 0;
        }
    }
    for(int j=1;j < E.size() ; j=j+2){
        if(E.at(j) == v){
            E.at(j) = 0;
            E.at(j-1) = 0;
        }
    }
    return E;
}



//グラフG=(V,E)と頂点vが与えられたときに、ｖをスタートして各頂点をちょうど一度だけ通るようなパスの総数を返す関数
int path(vector<int> V, vector<int> E, int v){
    //頂点数N
    int N = search(V,1);
    //vの次数d
    int d = search(E,v);
    if(d == 0 && N > 1){
        return 0;
    }
    if(d == 0 && N == 1){
        return 1;
    }
    else{
        vector<int> S = connect(E,v);
        for(int j=0; j < S.size(); j++){
            S.at(j) = path(vertex_delete(V,v),edge_delete(E,v),S.at(j)) ;
        }
        return sum(S);
    }
    
}


int main(){

//入力を受け取る
int N ;
cin >> N ;

int M ;
cin >> M;

//点集合Vを用意
//V=(0 1 1 1   1 1)で初期化。V.at(0)=0とした方がわかりやすいかなと
vector<int> V(N+1);
V.at(0) = 0;
for(int i=1;i < N+1; i++){
    V.at(i) = 1;
}

//辺集合Eの読み込み
vector<int> E(2*M);
for(int i=0 ; i< 2*M ; i++){
    cin >> E.at(i);
}



//テストコード
cout << path(V,E,1) << endl;



}