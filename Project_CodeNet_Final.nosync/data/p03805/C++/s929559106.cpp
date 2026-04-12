#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, M;
    bool G[8][8];
    int ans = 0;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            G[i][j] = false;
        }
    }
    for(int i = 1; i < N; i++){
        v.push_back(i);
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a-1][b-1] = true;
        G[b-1][a-1] = true;
    }
    if(N != 2){   
        do {
            if(G[0][v[0]]){
                for(int i = 0; i < N-2;i ++){
                    if(!G[v[i]][v[i+1]]) break;
                    if(i == N-3) ans++;
                }
            }
        } while (next_permutation(v.begin(), v.end()));
    }else{
        if(G[0][1])ans++;
    }
    cout << ans << endl;
}