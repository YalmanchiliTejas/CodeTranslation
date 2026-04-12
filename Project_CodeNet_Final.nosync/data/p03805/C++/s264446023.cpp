#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<bool>> path(8,vector<bool>(8,false));

int dfs(int v,int n, vector<bool> checked){
    int ans = 0;
    bool all_visited = true;
    for(int i=0;i<n;i++){
        if(checked.at(i) == false){
            all_visited = false;
            break;
        }
    }
    if(all_visited){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(path.at(v).at(i) == false || checked.at(i) == true){
            continue;
        }
        checked.at(i) = true;
        ans += dfs(i,n,checked);
        checked.at(i) = false;
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        path.at(a-1).at(b-1) = true;
        path.at(b-1).at(a-1) = true;
    }
    vector<bool> checked(8,false);
    checked.at(0) = true;
    int ans = dfs(0,n,checked);
    cout << ans << endl;
    return 0;
}