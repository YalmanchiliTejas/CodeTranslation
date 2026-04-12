#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int INF = 1 << 20;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
bool reached[8];
bool g[10][10];

int dfs(int now,int depth)
{
    if(reached[now]) return 0;
    if(depth == n) return 1;

    reached[now] = true;

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(g[now][i]){
            ans += dfs(i,depth+1);
        }
    }
    reached[now] = false;
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        reached[i] = false;
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a][b] = true;
        g[b][a] = true;
    }
    cout << dfs(0,1);
}