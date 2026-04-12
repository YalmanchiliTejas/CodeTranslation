#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
typedef long long llong;
static const int MAX = 10;

int n, m;
int ans;
vector< vector<int> > M(MAX + 1);
int d[MAX + 1];

void dfs(int x){
    int check = 0;
    for (int i = 1; i <= n; i++){
        if (d[i] < 0) check++;
    }
    if (check == n) ans++;
    for (int i = 0; i < M[x].size(); i++){
        if (d[M[x][i]] > 0){
            d[M[x][i]] = -1;
            dfs(M[x][i]);
            d[M[x][i]] = 1;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    int x, y;

    for (int i = 1; i <= n; i++) d[i] = 1;

    for (int i = 0; i < m; i++){
        cin >> x >> y;
        M[x].push_back(y);
        M[y].push_back(x);
    }
    ans = 0;
    d[1] = -1;
    dfs(1);
    cout << ans << endl;
    return 0;
}