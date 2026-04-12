#include <bits/stdc++.h>
using namespace std;

int route(vector<vector<int>> &graph, vector<int> arl, int pos){
    int num = 0;
    arl[pos]++;
    bool check = true;
    for(int i=1; i<arl.size(); i++){
        if(arl[i] == 0){
            check = false;
            break;
        }
    }
    if(check){
        return 1;
    }
    for(int i=0; i<graph[pos].size(); i++){
        if(arl[graph[pos][i]] == 0){
            num += route(graph,arl,graph[pos][i]);
        }
    }
    return num;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> arl(n+1,0);
    cout << route(graph, arl, 1) << endl;
}