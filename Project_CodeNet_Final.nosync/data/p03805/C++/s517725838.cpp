typedef int ll;
#include <bits/stdc++.h>
using namespace std;

ll N,M;
bool is_visited[8];
bool edges[28][28];

int dps(int start, bool visited[]){
    bool all_done = true;
    visited[start]=true;
    
    // for (int i = 0; i < N; i++) {
    //     std::cout << visited[i];
    // }
    // std::cout << std::endl;
    
    ll local_result =0;
    for (int i = 0; i < N; i++) {
        if(!visited[i]){
            all_done=false;
            break;
        }
    }
    // 全て探索が終わっていたらそのとおりを+1する。
    if(all_done){
       return 1;
    }
    
    for (int i = 0; i < N; i++) {
        // 自分自身、訪れたとこ、エッジがないところは省く
        if(i==start || visited[i] || !edges[start][i]){
            continue;
        }
        bool local_visited[8];
        memcpy(local_visited, visited, sizeof(bool) * 8);

        local_result+=dps(i,local_visited);
    }
    return local_result;
}

int main() {
    std::cin >> N>>M;
    for (int i = 0; i < M; i++) {
        ll tmp_a,tmp_b;
        std::cin >> tmp_a>>tmp_b;
        // 1ずらす
        edges[tmp_a-1][tmp_b-1]=true;
        edges[tmp_b-1][tmp_a-1]=true;
    }

    std::cout << dps(0,is_visited) << std::endl;
}
