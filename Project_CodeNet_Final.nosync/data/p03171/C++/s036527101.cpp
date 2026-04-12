#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
//priority_queue<int> pque;
//priority_queue<int, vector<int>, greater<int>> pque;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 1000000007;
int N;
vector<int> a(3010);
ll dp[3010][3010];

ll dfs(int x, int y){
    int turn = (N - y + x) % 2;
    if(dp[x][y] != INF){
        return dp[x][y];
    }else{
        if(x == y){
            if(turn){
                return dp[x][y] = a.at(x);
            }
            else return dp[x][y] = -a.at(x);
        }
        else{
            if(turn){
                return dp[x][y] = max(dfs(x+1, y) + a.at(x), dfs(x, y-1) + a.at(y));
            }
            else{
                return dp[x][y] = min(dfs(x+1, y) - a.at(x), dfs(x, y-1) - a.at(y));
            }
        }
    }
}


int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    
    for(int i = 0; i < 3010; i++){
        for(int j = 0; j < 3010; j++){
            dp[i][j] = INF;
        }
    }
    
    cout << dfs(0, N-1) << endl;
}
