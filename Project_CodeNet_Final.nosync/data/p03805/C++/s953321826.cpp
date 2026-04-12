#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
Graph G(10);

bool is_exited(vector<int> vec, int val){
    bool flag = false;
    for (int i = 0; i < vec.size(); ++i){
        if (vec[i] == val){
            flag = true;
            break;
        }
    }
    return flag;
}


int main(void){
    //////////////////////////
    // 方針
    // すべての順列を書き出す
    //////////////////////////


    // 入力
    int N, M; scanf("%d", &N); scanf("%d", &M);
    int a, b;
    for(int i = 0; i < M; ++i){
        scanf("%d", &a);
        scanf("%d", &b);
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ////////////////////////

    int ans = 0;
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    do {
        
        bool flag = true;
        if (v[0] != 0) break;
        int x, nx;
        for (int i = 0; i < N-1; ++i){
            x = v[i];
            nx = v[i+1];
            if (!is_exited(G[x], nx)) flag = false;
        }
        if(flag)  ++ans;
        
        //for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示

            
    }while(next_permutation(v.begin(), v.end()));

    printf("%d\n", ans);

   //////////////////////////
    return 0;
}