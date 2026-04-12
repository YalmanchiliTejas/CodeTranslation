#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=210003;
const ll INF=1LL<<60;

ll dp[MAX][3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(13+N);
    for(int i=0;i<N;i++) cin>>A[11+i];
    
    if(N%2==0){
        for(int i=11;i<=10+N;i++){
            dp[i][0]=dp[i][1]=-INF;
        }
        
        for(int i=11;i<=10+N;i++){
            if(i%2){
                dp[i][0]=max(dp[i][0],dp[i-2][0]+A[i]);
            }else{
                dp[i][1]=max(dp[i][1],dp[i-3][0]+A[i]);
                dp[i][1]=max(dp[i][1],dp[i-2][1]+A[i]);
            }
        }
        
        cout<<max(dp[10+N-1][0],dp[10+N][1])<<endl;
    }else{
        for(int i=0;i<=10+N;i++){
            dp[i][0]=dp[i][1]=dp[i][2]=-INF;
        }
        dp[9][0]=0;
        
        for(int i=11;i<=10+N;i++){
            dp[i][0]=max(dp[i][0],dp[i-2][0]+A[i]);
            
            dp[i][1]=max(dp[i][1],dp[i-2][1]+A[i]);
            dp[i][1]=max(dp[i][1],dp[i-3][0]+A[i]);
            
            dp[i][2]=max(dp[i][2],dp[i-2][2]+A[i]);
            dp[i][2]=max(dp[i][2],dp[i-3][1]+A[i]);
            dp[i][2]=max(dp[i][2],dp[i-4][0]+A[i]);
        }
        
        cout<<max({dp[10+N-2][0],dp[10+N-1][1],dp[10+N][2]})<<endl;
    }
}
