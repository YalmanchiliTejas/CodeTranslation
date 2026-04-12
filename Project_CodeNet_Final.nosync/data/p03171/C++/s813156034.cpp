// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;
typedef  long long  ll;
int N,a[maxn];
ll dp[maxn][maxn];

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>a[i];
        dp[i][i] = a[i];
    }
    
    for(int i = 2; i<=N; i++ ){
        for(int j = 0; j<= N-i;j++){
            dp[j][j+i-1] = max(a[j]-dp[j+1][j+i-1], a[j+i-1] - dp[j][j+i-2]);
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}




