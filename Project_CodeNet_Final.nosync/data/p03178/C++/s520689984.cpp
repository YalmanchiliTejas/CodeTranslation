#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

// i桁/和j/k以下確定
long long dp[10010][110][2];
int main(){
    string K; cin>>K;
    int digit=K.size();
    int n; cin>>n;
    dp[0][0][0]=1;
    for(int i=1;i<=digit;i++){
        int nn=K[i-1]-'0';
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                // 確定してたら上限固定
                for(int d=0;d<=(k?9:nn);d++){
                    // 確定更新
                    dp[i][j][k||(d<nn)]+=dp[i-1][mod(j-d,n)][k];
                    dp[i][j][k]%=MOD;
                }
            }
        }
    }
    cout<<mod(dp[digit][0][0]+dp[digit][0][1]-1,MOD)<<endl;
    return 0;
}
