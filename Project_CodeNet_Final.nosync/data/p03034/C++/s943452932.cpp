#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    ll N;cin>>N;
    vector<ll> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    ll ans=0;
    
    for(ll C=1;C<=N-1;C++){
        ll sum=0;
        for(ll k=1;N-1-(k+1)*C>0;k++){
            if((N-1)%C==0&&(N-1)/C<=2*k) break;
            sum+=S[k*C];
            sum+=S[N-1-k*C];
            ans=max(ans,sum);
            //cout<<C<<" "<<k<<" "<<sum<<endl;
        }
    }
    
    cout<<ans<<endl;
}
