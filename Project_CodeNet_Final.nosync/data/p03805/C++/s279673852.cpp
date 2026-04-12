#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e6;

int n, m;
vector< vector<bool> > mat(10, vector<bool>(10, false));
long long ans=0;


void search(int v, vector<bool> visited){
    bool all_visited = true;
    for (int i=0; i<n; i++){
        all_visited = all_visited && visited[i];
    }
    if (all_visited){
        ans++;
        return;
    }

    for (int i=0; i<n; i++){
        if (i != v && mat[v][i] && !visited[i]){
            vector<bool> _visited = visited;
            _visited[i] = true;
            search(i, _visited);
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        mat[a-1][b-1] = true;
        mat[b-1][a-1] = true;
    }

    vector<bool> visited(10, false);
    visited[0] = true;
    search(0, visited);

    cout << ans << endl;
}