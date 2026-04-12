#include<bits/stdc++.h>
using namespace std;

#define int long long

int cache[3005][3005];
int data[3005];

int solve(int i, int j, int parity){
    if(i > j){
        return 0;
    }
    int &res = cache[i][j];
    
    if(res != -1){
        return res;
    }
    
    if(!parity){
        res = max(data[i] + solve(i+1, j, parity^1), data[j] + solve(i, j-1, parity^1));
    }
    else{
        res = min(-data[i] + solve(i+1, j, parity^1), -data[j] + solve(i, j-1, parity^1));
    }
    
    return res;
}

signed main(){
    
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> data[i];
    }
    
    cout << solve(1, n, 0) << '\n';
}