#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int i = 0;
    int j = 0;
    int a, b;
    int graph[n][n];
    int ans = 0;
    int flag = 1;
    vector<int> v;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            graph[i][j] = 0;
        }
        v.push_back(i);
    }
    
    for(i = 0; i < m; i++){
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    
    do{
        if(v[0] != 0){
            continue;
        }
        flag = 1;
        for(i = 0; i < n-1; i++){
            if(graph[v[i]][v[i+1]] == 0){
                flag = 0;
            }
        }
        if(flag){
            ans++;
        }
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;
}

