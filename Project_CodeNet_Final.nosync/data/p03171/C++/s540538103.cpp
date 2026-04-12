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

    for (int l=2;l<=N;l++){
        for (int i=0,j=l-1;j<N;i++,j++){
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}




