#include <iostream>
#include <queue>
using namespace std;
int main(void){
    // Your code here!
    int N, M;
    int field[500][500];
    int field_dist[500][500];
    vector<vector<int>> edges(8, vector<int>());
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    int count = 0;
    queue<vector<int>> q;
    vector<int> init{0};
    for(int i = 0; i < N; i++)
        init.push_back(0);
    init[1] = 1;
    q.push(init);
    while(q.size() > 0){
        vector<int> cur = q.front();
        q.pop();
        
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += cur[i+1];
            
        if(sum == N){
            count++;
            continue;
        }
        
        for(auto e:edges[cur[0]]){
            if(cur[e+1] == 0){
                vector<int> temp{e};
                for(int i = 0; i < N; i++)
                    temp.push_back(cur[i+1]);
                temp[e+1] = 1;
                q.push(temp);
            }
            
        }
    }
    
    cout << count << endl;
    
    return 0;    
}
