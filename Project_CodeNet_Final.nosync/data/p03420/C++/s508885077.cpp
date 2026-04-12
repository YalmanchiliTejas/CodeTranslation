#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    ll N,K;
    cin>>N>>K;
    if(K==0){
        cout<<N*N<<endl;
        return 0;
    }
    ll ans=0;
    for(int b=1;b<=N;++b){
        if(b-1<K) continue;
        ll maxs=N/b;
        ans+=maxs*(b-K);
        ll maxt= N-maxs*b;
        ans+=max(maxt-K+1,0LL);
    }
    cout<<ans<<endl;
}
