#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,K; cin>>N>>K;

    int64_t ans=0;
    rep(b,K+1,N+1){
        ans+=(N/b)*(b-K);
        ans+=max(0,N%b-K+1);
    }
    if(!K) ans-=N;

    cout<<ans<<endl;
}