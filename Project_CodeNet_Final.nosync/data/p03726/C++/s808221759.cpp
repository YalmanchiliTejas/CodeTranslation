#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
vector<int>g[100000];
int dp[100000][2];
void dfs(int s, int p){
    int ma = -1000000;
    for(int x:g[s]){
        if(x == p)continue;
        dfs(x,s);
        dp[s][0] += dp[x][1];
        ma = max(ma, dp[x][0] - dp[x][1]);
    }
    dp[s][1] = dp[s][0] + 1 + ma;
}
int main(){
    int n;
    cin >> n;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1);
    if(n%2==0 and dp[0][1] == n/2){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
}