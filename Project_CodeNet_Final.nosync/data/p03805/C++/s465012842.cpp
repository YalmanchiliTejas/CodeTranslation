#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> nodes(n);
    for(int i=0; i<n; ++i) nodes[i]=i;
    vector<vector<bool>> edges(n, vector<bool>(n));
    for(int i=0; i<m; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        edges[a][b]=edges[b][a]=true;
    }
    int ans=0;
    do{
        ++ans;
        for(int i=1; i<n; ++i){
            if(!edges[nodes[i-1]][nodes[i]]){
                --ans;
                break;
            }
        }
    } while(next_permutation(nodes.begin()+1, nodes.end()));
    cout << ans << endl;
    return 0;
}
