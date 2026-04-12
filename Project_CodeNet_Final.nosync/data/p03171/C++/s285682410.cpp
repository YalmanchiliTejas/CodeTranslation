#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll dp[N+5][N+5];
    for(int i=0;i<N+5;i++){
        for(int j=0;j<N+5;j++){
            dp[i][j]=0;
        }
    }
    for(int len=1;len<=N;len++){
        for(int i=0;i+len<=N;i++){
            int j=i+len;
            if((N-len)%2==0){
                dp[i][j]=max(dp[i+1][j]+A[i],dp[i][j-1]+A[j-1]);
            }else{
                dp[i][j]=min(dp[i+1][j]-A[i],dp[i][j-1]-A[j-1]);
            }
        }
    }
    cout<<dp[0][N]<<endl;
}
