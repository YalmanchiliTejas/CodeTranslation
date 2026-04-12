#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<ll> s(N);
    rep(i,N){
        cin>>s.at(i);
    }
    ll ans=0;
    vector<ll> S(N);//indexの和がN-1になる物をペアにして和をとる
    rep(i,N){
        S.at(i)=s.at(i)+s.at(N-1-i);
    }
    
    for(int aminusb=1;aminusb<N-1;aminusb++){
        ll nowsum=0;

        if((N-1)%aminusb==0){
            for(int i=0;2*i<(N-1)/aminusb;i++){
                nowsum+=S.at(i*aminusb);
                chmax(ans,nowsum);
            }
        }
        
        else{
            for(int i=0;(i+1)*aminusb<N-1;i++){
                nowsum+=S.at(i*aminusb);
                chmax(ans,nowsum);
            }
        }
    }
    cout<<ans<<endl;
}