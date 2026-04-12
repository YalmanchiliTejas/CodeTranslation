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
    int temp = 0;
    int mi = 1000000;
    int id = 0;
    for(int x:g[s]){
        if(x == p)continue;
        dfs(x,s);
        dp[s][0] += dp[x][1];
    }
    for(int x:g[s]){
        if(x == p)continue;
        dp[s][1] = max(dp[s][1], dp[s][0] + 1 - dp[x][1] + dp[x][0]);
    }
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