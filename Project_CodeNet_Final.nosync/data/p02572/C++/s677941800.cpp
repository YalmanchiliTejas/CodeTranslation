#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
ll d=1e9+7;

int main(){
    int n;cin>>n;
    ll A[n],B[n];
    rep(i,n){cin>>A[i];B[i]=A[i];}
    for(int i=1;i<n;i++){
        A[i]+=A[i-1];
        A[i]%=d;
    }
    ll ans=0;
    for(int j=1;j<n;j++){
        ans+=B[j]*(A[j-1]);
        ans%=d;
    }
    cout<<ans<<endl;
    return 0;
}