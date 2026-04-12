#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> S(N);
    vector<int> dp(2*N,INF);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        S[i]=-a;
    }
    
    for(int i=0;i<N;i++){
        *upper_bound(all(dp),S[i])=S[i];
    }
    
    for(int i=0;i<2*N;i++){
        if(dp[i]==INF){
            cout<<i<<endl;
            break;
        }
    }
}
