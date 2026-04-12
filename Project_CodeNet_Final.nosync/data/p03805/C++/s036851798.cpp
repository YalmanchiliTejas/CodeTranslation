#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;// number of nodes & edges
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    vector<int> paths(n-1);
    for(int i=0; i<n-1; i++){
        paths[i] = i+1;// 0-indexed
    }

    do{
        vector<int> p(n);// p[0] = 0
        for(int i=1; i<n; i++) p[i] = paths[i-1];
        
        int flag = 0;
        for(int i=0; i<n-1; i++){
            for(auto adjacent : graph[p[i]]){
                if(adjacent == p[i+1]){
                    flag += 1;
                    break;
                }
            }
        }
        if(flag == n-1) ans += 1;
    }while(next_permutation(paths.begin(),paths.end()));
    cout << ans << endl;
    return 0;
}