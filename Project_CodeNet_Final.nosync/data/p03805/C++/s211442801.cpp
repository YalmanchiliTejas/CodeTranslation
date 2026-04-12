#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;

int ans = 0;
int g[8][8];
int check[8];
int n,m;

void dfs(int next)
{
    bool all = true;
    for(int i = 0; i < n; i++){
        if(check[i] == 0){
            all = false;
        }
    }
    if(all) ans++;

    for(int i = 0; i < n; i++){
        if((g[i][next] == 1 || g[next][i] == 1 ) && check[i] == 0){
            check[i] = 1;
            dfs(i);
            check[i] = 0;
        }
    }
    return ;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        
    }
    check[0] = 1;
    dfs(0);
    cout << ans << endl;
}
