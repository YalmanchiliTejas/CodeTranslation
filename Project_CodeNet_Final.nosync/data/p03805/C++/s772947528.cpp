#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > edges;

bool isValid(vector<int> v){
    if(v[0] != 0)
        return false;
    for(int i = 0; i< v.size()-1; i++){
        if(!edges[v[i]][v[i+1]]){
            return false;
        }
    }
    return true;
}

int main() {
    int n,m; cin >> n >> m;
    vector<int> edge(n,0);
    vector<int> v;
    for(int i = 0;i<n;i++){
        v.push_back(i);
        edges.push_back(edge);
        for(int j = 0; j< n;j++){
            edges[i][j] = 0;
        }
    }
    int from,to;
    for(int i = 0; i< m;i++){
        cin >> from >> to;
        edges[from-1][to-1] = 1;
        edges[to-1][from-1] = 1;
    }
    int count = 0;
    do {
        if(isValid(v)){
            count++;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << count << endl;
}
