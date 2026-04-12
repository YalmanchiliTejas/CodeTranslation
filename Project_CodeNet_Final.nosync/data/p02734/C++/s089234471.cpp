#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=3003,INF=1<<30;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,S;cin>>N>>S;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    dp[0][0]=1;
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        dp[i+1][A[i]]+=i+1;
        dp[i+1][A[i]]%=mod;
        for(int j=1;j<=S-1;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=mod;
            
            if(j+A[i]<=S) dp[i+1][j+A[i]]+=dp[i][j];
            dp[i+1][j+A[i]]%=mod;
        }
        ans+=dp[i+1][S]*ll((N-i));
        ans%=mod;
    }
    
    cout<<ans<<endl;
}
