#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ll N,K;
    cin>>N>>K;
    if(K==0){
        cout<<N*N<<endl;
        return 0;
    }
    ll a;
    ll hoge;
    ll ans=0;
    rep(i,N-K){
        a=K+i+1;
        hoge=(N-K)/a;
        ans+=hoge*(a-K);
        if(N%a<K) ans+=a-K;
        else ans+=N%a-K+1;
    }
    cout<<ans<<endl;
    return 0;
}