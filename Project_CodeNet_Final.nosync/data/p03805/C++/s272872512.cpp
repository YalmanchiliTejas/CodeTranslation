#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for (int i=0;i<n;i++)

ll mod = 1e9+7;

int ans = 0;
vector<bool> path;
vector<vector<int> > ab;

void dfs(int pos){
    bool visited = true;
    rep(i,path.size()){
        if (!path[i]){
            visited = false;
            break;
        }
    }
    if (visited){
        ans++;
        return;
    }
    for (auto i:ab[pos]){
        if (path[i]) continue;
        path[i] = true;
        dfs(i);
        path[i] = false;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    ab = vector<vector<int> >(n);
    path = vector<bool>(n,false);
    path[0] = true;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ab[a-1].push_back(b-1);
        ab[b-1].push_back(a-1);
    }
    dfs(0);
    cout << ans << endl;
}