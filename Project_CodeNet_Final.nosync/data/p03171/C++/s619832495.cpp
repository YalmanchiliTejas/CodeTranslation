#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#define PIE 3.14159265358979
#define rep(i,n) for(int i = 0;i < (n);i++)
#define MAX_N 3005
using namespace std;
typedef long long ll;

ll dp[MAX_N][MAX_N];
int N;
ll a[MAX_N];

ll dfs(int i,int j){ //i枚目まで投げた時、j枚おもての確率
    if(dp[i][j]>=0){
        return dp[i][j];
    }
    if(i==j){
        dp[i][j]=0;
        return 0;
    }
    ll ret = max(a[i]-dfs(i+1,j),a[j-1]-dfs(i,j-1));
    dp[i][j]=ret;
    return ret;
}

int main() {
    cin>>N;
    rep(i,N){
        cin>>a[i];
    }
    rep(i,MAX_N){
        rep(j,MAX_N){
            dp[i][j]=-1;
        }
    }
    cout<<dfs(0,N)<<endl;
}

