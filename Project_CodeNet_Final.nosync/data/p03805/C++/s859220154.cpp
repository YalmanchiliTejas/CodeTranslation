#include<iostream>
#include <algorithm>
#include<vector>
#include<map>
#include <set>
#include<string>
#include <queue>
#include <stack>
#include <random>
#define INF 1000000001
#include<iostream>
#include<vector>
using ll = long long;

int main()
{    

    int N, M;
    std::cin >> N >> M ;
    bool edge[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            edge[i][j] = false;
        }
    }

    for(int i = 0; i < M; ++i){
        int from, to;
        std::cin >> from >> to;
        edge[from - 1][to-1] = true;
        edge[to-1][from-1] = true;
    }


    int node[N];
    for(int i = 0; i < N; ++i){
        node[i] = i;
    }

    int cnt = 0;
    do{
        if(node[0] != 0) break;
        // for(int k = 0; k < N; ++k){
        //     std::cout << node[k];
        // }
        // std::cout << "\n";

        bool fail = false;
        for(int i = 0; i < N-1; ++i){
            if(!edge[node[i]][node[i+1]]){
                fail = true;
                break;
            }
        }
        if(!fail){
             cnt++;
             
        }
    }while(std::next_permutation(node, node + N));
    
   
   std::cout << cnt << std::endl;
   return 0;
    
}

