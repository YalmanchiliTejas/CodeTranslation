#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
//vector<int> Edge[30];
array<array<bool, 9>, 9> Edge;
// 行ったことがなければtrue
array<bool, 9> check;
//array<array<bool, 9>, 9> Edge;
int N, M;

int Func(int n, array<array<bool, 9>, 9> e, array<bool, 9> c){
    bool check0 = true;
    for(int i = 0; i < N; ++i){
        if(c[i]){
            check0 = false;
            break;
        }
    }
    if(check0) return 1;
    int res = 0;
    for(int i = 0; i < N; ++i){
        if(e[n][i] && c[i]){
            c[i] = false;
            e[n][i] = false;
            e[i][n] = false;
            res += Func(i, e, c);
            c[i] = true;
            e[n][i] = true;
            e[i][n] = false;
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        Edge[a][b] = true;
        Edge[b][a] = true;
        /*
        Edge[a].push_back(b);
        Edge[b].push_back(a);*/
    }
    for(int i = 0; i < N; ++i){
        check[i] = true;
    }
    check[0] = false;
    cout << Func(0, Edge, check) << endl;

    return 0;
};