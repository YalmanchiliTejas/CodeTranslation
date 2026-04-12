#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105,INF=1<<30;
ll dp[MAX][MAX];

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> h(N+2,1),num(N+2,1),hi(N+2,1);
    vector<ll> SE;
    SE.push_back(1);
    for(int i=0;i<N;i++){
        cin>>h[i+1];
        SE.push_back(h[i+1]);
    }
    if(N==1){
        cout<<rui(2,h[1])<<endl;
        return 0;
    }
    
    sort(all(SE));
    SE.erase(unique(all(SE)),SE.end());
    
    ll M=SE.size();
    
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M;j++){
            if(SE[j]==h[i]){
                num[i]=j;
                break;
            }
        }
    }
    
    for(int i=0;i<M;i++){
        hi[i]=SE[i];
    }
    
    dp[0][0]=1;
    
    for(int i=1;i<=N;i++){
        if(h[i-1]>=h[i]){
            for(ll from=M-1;from>=num[i];from--){
                dp[i][num[i]]+=dp[i-1][from]*2;
                dp[i][num[i]]%=mod;
            }
            for(ll j=num[i]-1;j>=0;j--){
                dp[i][j]+=dp[i-1][j];
            }
        }else{
            dp[i][num[i]]+=dp[i-1][num[i-1]]*2%mod;
            
            for(ll j=num[i]-1;j>=num[i-1];j--){
                dp[i][j]+=dp[i-1][num[i-1]]*2%mod*rui(2,h[i]-hi[j+1])%mod*(rui(2,hi[j+1]-hi[j])-1)%mod;
            }
            
            for(ll j=num[i-1]-1;j>=0;j--){
                dp[i][j]+=dp[i-1][j]*rui(2,h[i]-h[i-1])%mod;
            }
        }
    }
    
    ll ans=0;
    
    for(int j=0;j<M;j++){
        ans+=dp[N][j];
        ans%=mod;
    }
    
    cout<<ans<<endl;
    
}
