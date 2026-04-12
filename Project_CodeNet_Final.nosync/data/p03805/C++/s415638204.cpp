#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// グラフを隣接行列で管理する //pathがあるかどうかだけが今回の関心事項だから
bool G[10][10];

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = G[b][a] = true;
    }

    //順列
    vector<int> ord(N);
    for(int i = 0; i < N; i++) ord[i] = i;

    //順列を全部試す
    int res = 0; //pathの数を記録する
    do{
        if(ord[0] != 0) break; //本問題では頂点1(i = 0)からスタートしなければならないから

        bool ok = true;
        for(int i = 0; i +1 < N; i++){
            int from = ord[i]; //先程のif文チェックを通過しているから, ord[0] = 0;
            int to = ord[i+1]; //次の移動先頂点
            if(!G[from][to]) ok = false; //G[from][to] = falseという場合, from-to上の辺が存在しない（移動不可）
        }
        if(ok) ++res; //ok = trueは, 頂点1からラスの頂点まで到達するpathの存在を意味する

    }while(next_permutation(ord.begin(), ord.end())); //順列を考えることで, すべての点を一回だけ通ることが保証される

    std::cout << res << std::endl;
    return 0;
}