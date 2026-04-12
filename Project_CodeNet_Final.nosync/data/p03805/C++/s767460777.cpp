//
// Created by Tetsuya Shiota on 2019-04-13.
//

#include<iostream>
#include<vector>


using namespace std;

class Solver{
public:
    vector<vector<bool>> edge;
    int N, M;
    Solver(){
        cin >> N >> M;

        for(int i = 0; i<N; i++){
            edge.push_back(vector<bool>(N));
            for(int j=0;j<N;j++){
                edge[i][j] = false;
            }
        }

        for(int i =0; i<M; i++){
            int a, b;
            cin >> a >> b;
            a--;b--;
            edge[a][b] = edge[b][a] = true;
        }
    }

    int solve(int now, int cnt, vector<bool> &visited){
        if(cnt == N)return 1;

        int ret = 0;
        visited[now] = true;
        for(int i = 0; i<N; i++){
            if(visited[i])continue;
            if(!edge[now][i])continue;
            ret += solve(i, cnt+1, visited);
        }
        visited[now] = false;

        return ret;
    }

    int solve(){
        int now = 0;
        vector<bool> visited(N);
        return solve(now, 1, visited);
    }
};


int main(){
    auto solver = Solver();
    cout << solver.solve() <<endl;
}