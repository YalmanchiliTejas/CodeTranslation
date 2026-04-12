#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> path(8);
vector<bool> visited(8);
int N,ans=0;

void visit_node(int start){
    bool all_visit = true;
    for(int i=0; i<N; i++){
        if(!visited[i]){
            all_visit = false;
            break;
        }
    }
    if(all_visit){
        ans++;
        return;
    }
    for(int i=0; i<(int)path[start].size(); i++){
        if(!visited[path[start][i]]){
            visited[path[start][i]]=true;
            visit_node(path[start][i]);
            visited[path[start][i]]=false;
        }
    }
}
int main(){
    int M,a,b;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> a >> b;
        a--;
        b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    visited[0]=true;
    visit_node(0);

    cout << ans << endl;
    return 0;
}