#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <climits>
#include <unordered_map>
#include <numeric>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<int,int> pii;
ll a[3000];
ll dp[3000][3000];
ll dfs(int x,int y){
    if(x>y)return dp[x][y] = 0;
    if(dp[x][y] != -1)return dp[x][y];
    return dp[x][y] = max(a[x] - dfs(x+1,y), a[y] - dfs(x,y-1));
}
int main(){
    int n;
    cin >> n;
    rep(i,n)cin >> a[i];
    rep(i,n)rep(j,n)dp[i][j] = -1;
    cout << dfs(0,n-1) << endl;
}
