#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    ll n,ans=0;
    cin>>n;

    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        a[i]%=mod;
    }

    vector<ll>A(n);
    A[n-1]=a[n-1];
    repr(i,n-2,0){
        A[i]=(a[i]+A[i+1])%mod;
    }

    rep(i,n-1){
        ans+=(a[i]*A[i+1])%mod;
    }

    cout<<ans%mod<<endl;
}
