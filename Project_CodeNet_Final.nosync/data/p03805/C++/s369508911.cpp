#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); i++)
using vvi = vector<vector<int>>;

int main(){
    int n, m; cin >> n >> m;
    vvi graph;
    rep(i, n){
        vector<int> z(n, 0); graph.push_back(z);
    }
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        graph[a][b] = 1; graph[b][a] = 1;
    }
    vector<int> v; rep(i, n) v.push_back(i);
    iota(v.begin(), v.end(), 1);
    vector<vector<int>> paths;
    do {
        vector<int> i;
        for(auto x : v){
            i.push_back(x-1);
        }
        paths.push_back(i);
    } while( next_permutation(v.begin(), v.end()));  

    int success = 0;
    for (auto path: paths){
        int curr = path[0];
        if (curr != 0) continue;
        bool pass = true;
        rep(i, path.size()-1){
            if (graph[curr][path[i+1]] != 1) pass = false;
            curr = path[i+1];
        }
        if (pass) success++;
    }

    cout << success << endl;
}   
