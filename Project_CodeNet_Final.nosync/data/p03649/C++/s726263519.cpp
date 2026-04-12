#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    ll N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    bool ok=true;
    ll ans=0;
    
    while(ok){
        ok=false;
        ll cnt=0;
        vector<ll> B(N,0);
        for(int i=0;i<N;i++){
            cnt+=A[i]/N;
            B[i]=A[i]/N;
            
            A[i]=A[i]%N;
        }
        
        for(int i=0;i<N;i++){
            A[i]+=(cnt-B[i]);
            if(A[i]>=N) ok=true;
        }
        
        ans+=cnt;
    }
    
    cout<<ans<<endl;
}
