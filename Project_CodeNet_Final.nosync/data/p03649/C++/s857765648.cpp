#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N;
    cin >> N;
    ll K=0;
    vector<ll> a(N,0);
    for(ll i=0;i<N;i++){
        cin>>a[i]
    ;}
    sort(a.begin(), a.end());
    while(a[N-1]>=N){
        ll t=(a[N-1]-N+1)/N;
        a[N-1]-=t*N;
        if(a[N-1]>=N){a[N-1]-=N;t++;};
        K+=t;
        for(ll i=0;i<N-1;i++){
            a[i]+=t;;}
        sort(a.begin(), a.end());
    }
    cout<<K<<endl;
    return 0;
}
