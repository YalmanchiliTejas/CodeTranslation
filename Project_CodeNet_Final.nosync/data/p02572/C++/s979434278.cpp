#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    ll MOD=1e9+7;
    ll ans=0;
    int N; cin>>N;
    int A[N];
    rep(i,N)cin>>A[i];
    ll SUM[N];
    ll a=0;
    rep(i,N-1){
        a+=A[i+1];
    }
    SUM[0]=0;
    SUM[1]=a;
    rep(i,N-2){
        SUM[i+2]=SUM[i+1]-A[i+1];
    }
    rep(i,N-1){
        ll b=(SUM[i+1]%MOD)*A[i]%MOD;
        ans+=b;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}