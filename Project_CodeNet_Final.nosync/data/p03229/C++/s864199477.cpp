#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}
    sort(A.begin(), A.end());
    ll ans=0;
    ll t=A[N/2];
    if(N%2){
        for(ll i=0;i<N;i++){
                ans+=2*llabs(A[i]-t);
        ;}
        ans-=min(llabs(A[N/2+1]-A[N/2]),llabs(A[N/2-1]-A[N/2]));
    }
    else {
        for(ll i=0;i<N;i++){
            if(i!=N/2&&i!=N/2-1){
                ans+=2*llabs(A[i]-t);
            }
        ;}
        ans+=llabs(A[N/2]-A[N/2-1]);
    }
    cout<<ans<<endl;

    
    return 0;
}
