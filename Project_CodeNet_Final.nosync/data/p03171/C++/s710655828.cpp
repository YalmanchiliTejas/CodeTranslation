#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 1000000007;

int N;
vector<ll> a(3010);
ll memo[3010][3010];

void init(){
    for(int i = 0; i < 3010; i++){
        for(int j = 0; j < 3010; j++){
            memo[i][j] = INFL;
        }
    }
}

ll dfs(int x, int y){
    if(memo[x][y] != INFL){
        return memo[x][y];
    }
    bool turn = (N + x + y) % 2;
    if(x == y){
        if(turn) return memo[x][y] = a.at(x);
        return memo[x][y] = -a.at(x);
    }
    if(turn){
        return memo[x][y] = max(dfs(x+1, y) + a.at(x), dfs(x, y-1) + a.at(y));
    }else{
        return memo[x][y] = min(dfs(x+1, y) - a.at(x), dfs(x, y-1) - a.at(y));
    }
}




int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    init();
    cout << dfs(0, N-1) << endl;
    
    
    
}