#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N,K;
    cin>>N>>K;
    ll ans = 0;

    for(ll b=1; b<=N; b++){
        ans += N/b * max(b-K,0ll); 
        if(N%b){
            ans += max(N%b - K + 1,0ll); 
        }
    }

    if(K == 0) ans = N*N;

    cout<<ans<<endl;
}