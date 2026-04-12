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
    vector<ll> H(N+1,0);
    ll ans=0;
    for(ll i=0;i<N;i++){
        cin>>H[i+1];
        bool check=0;
        for(ll j=0;j<i+1;j++){
            if(H[j]>H[i+1])check=1;
        ;}
        if(!check)ans++;
    ;}
    cout<<ans<<endl;
    return 0;
}
