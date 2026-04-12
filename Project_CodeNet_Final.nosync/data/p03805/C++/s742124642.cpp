#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<bool>> graph(N, std::vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int a, b;
        std::cin >> a >> b;
        a--; b--; // to 0 origin
        graph[a][b] = true;
        graph[b][a] = true;
    }


    std::vector<int> order(N);
    for(int i = 0; i < N; i++) order[i] = i;
    int cnt = 0;

    // orderの左端は常に0であることに注意
    do{
        bool isReached = true;
        for(int i = 0; i < N - 1; i++){
            if(!graph[order[i]][order[i + 1]]){
                isReached = false;
                break;
            }
        }

        if(isReached) cnt++;
    }while(std::next_permutation(order.begin() + 1, order.end()));

    std::cout << cnt << std::endl;

    return 0;
}