//g++でビルド

#include "bits/stdc++.h"

using namespace std;

int n;
long long dp[3333][3333];
bool dp_bool[3333][3333];
vector<int> as;

long long dfs(int a, int b){
    if(dp_bool[a][b]){
        return dp[a][b];
    }

    if(b==0){
        dp[a][0] = 0;
    }else if(b==1){
        dp[a][1] = as[a];
    }else{
        dp[a][b] = max(as[a] - dfs(a+1, b-1), as[a+b-1] - dfs(a, b-1));
    }
    dp_bool[a][b] = true;
    return dp[a][b];
}

int main(){
    cin >> n;
    as.resize(n);
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            dp_bool[i][j] = false;
        }
    }

    long long result = dfs(0, n);

/*
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
*/
    

    
    cout << result << endl;
    return 0;
}