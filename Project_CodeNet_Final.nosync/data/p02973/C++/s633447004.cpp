#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)

int main(){
	ll N; cin>>N;
    vector<ll>A(N);
    ll ans=0;
    rep(i,N) cin>>A[i];
    multiset<ll> C;
    C.insert(A[0]);

    rep1(i,N-1){
        auto it=C.lower_bound(A[i]);
        if(it==C.bg){
            C.insert(A[i]);
        }
        else{
            it--;
            C.erase(it);
            C.insert(A[i]);
        }
    }
    cout<<sz(C);
}