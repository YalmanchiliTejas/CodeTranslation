#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n; ++i)
#define ALL(a) (a).begin(),(a).end()


int n, m;
vector<pair<int, vector<int>>> c(10);
bool visited[10] = {false};

int dfs(int x, int len){
    if(++len >= n)return 1;
    visited[x] = true;
    int path = 0;
    rep(i, c[x].second.size()){
        int pos = c[x].second[i];
        if(visited[pos])continue;
        path  += dfs(pos,  len); 
    }
    visited[x] = false;
    return path;
}
int main(){
    
    cin >> n >> m;
    int a[m], b[m];
    rep(i, m){
        cin >> a[i] >> b[i];
        c[a[i]].second.push_back(b[i]);
        c[b[i]].second.push_back(a[i]);
    }

    cout << dfs(1, 0);


}