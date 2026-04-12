#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define int long long
using namespace std;
const int MAX_N = 3000;
deque<int> a;
int N;
int dp[2][MAX_N+1][MAX_N+1];

signed main(){
    cin>>N;
    a.resize(N);
    REP(i, N) cin >> a[i];
    for(int i=N-1;i>=0;--i){
        for(int j=N-1;j>=0;--j){
            REP(k,2){
                if(i+j<N) dp[k][i][j]=k?min(dp[1-k][i+1][j]-a[i],dp[1-k][i][j+1]-a[N-1-j])
                                       :max(dp[1-k][i+1][j]+a[i],dp[1-k][i][j+1]+a[N-1-j]);
            }
        }
    }
    cout<<dp[0][0][0]<<endl;
}