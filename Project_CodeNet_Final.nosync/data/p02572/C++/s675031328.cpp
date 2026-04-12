#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll MOD=1000000007;

int main(){
    ll N;cin>>N;
    vector<ll>A(N);
    rep(i,N){
        cin>>A[i];
    }
    vector<ll>B(N);
    B[N-1]=A[N-1];
    rep(i,N-1){
        B[N-2-i]=(A[N-2-i]+B[N-1-i])%MOD;
    }
    ll ans=0;
    rep(i,N-1){
        ans+=(A[i]*B[i+1])%MOD;
        ans=ans%MOD;
    }
    cout<<ans<<endl;
}