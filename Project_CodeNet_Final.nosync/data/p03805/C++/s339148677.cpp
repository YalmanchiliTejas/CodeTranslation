#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool> > adj(n, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
    }
    vector<int> p(n);
    for(int i=0; i<n; i++){
        p[i] = i;
    }
    int ans = 0;
    do{
        bool success = true;
        for(int i=0; i<n-1; i++){
            if(!adj[p[i]][p[i+1]]){
                success = false;
                break;
            }
        }
        if(success){
            ans++;
        }
    }while(next_permutation(p.begin()+1, p.end()));
    cout << ans << endl;
    return 0;
}
