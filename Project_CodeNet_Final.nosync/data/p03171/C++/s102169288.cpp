#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n;
int a[3005];
long long dp[3005][3005][2];
int turn = 0;

long long recur(int i, int j, int turn){
    if(i == j){
        return (turn == 0 ? a[i] : -a[i]);
    }
    long long &r = dp[i][j][turn];
    if(r != inf) return dp[i][j][turn];
    if(turn == 0){
        return r = max(a[i] + recur(i+1,j,1-turn),a[j] + recur(i,j-1,1-turn));
    } else return r = min(-a[i]+recur(i+1,j,1-turn),-a[j] + recur(i,j-1,1-turn));
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = inf;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<recur(0,n-1,turn);
}
