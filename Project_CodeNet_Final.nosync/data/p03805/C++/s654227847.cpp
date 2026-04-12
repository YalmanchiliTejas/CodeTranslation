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

vector<int> tree[9];
int pass[9];
int n,m,ans;
void dfs(int v, int d) {
    if(d==n) {
        ans++;
        return;
    }
    for(int i = 0; i < tree[v].size(); i++) {
        if(pass[tree[v][i]]==0) {
            pass[tree[v][i]] = 1;
            dfs(tree[v][i],d+1);
            pass[tree[v][i]] = 0;
        }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    pass[0] = 1;
    dfs(0,1);
    cout << ans << endl;


    return 0;
}