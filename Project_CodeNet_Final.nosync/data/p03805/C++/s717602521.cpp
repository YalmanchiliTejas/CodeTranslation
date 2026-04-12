#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include<limits.h>
#include<iomanip>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define check(v) rep(i,v.size()) cout << v[i] << " ";\
cout << endl
#define INF 1e8
typedef long long ll;
using namespace std;
//オーバーフローに気をつけろよおおおおおお
//確認忘れるなよおおおおおお

int n, m, ans, node1, node2, x[9]={1};
vector<int> G[9];

void dfs(int p, int q){
    if(q==n) {
        ans++;
        return;
    }
    for(auto a : G[p]){
        if(!x[a]){
            x[a] = 1;
            dfs(a,q+1);
            x[a] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    rep(i,m){
        cin >> node1 >> node2;
        node1--; node2--;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
    }
    dfs(0,1);
    cout << ans << endl;
    return 0;
}