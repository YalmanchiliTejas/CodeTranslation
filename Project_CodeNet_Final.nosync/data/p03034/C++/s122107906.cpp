#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)

template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
    ll N; cin>>N;
    vector<ll>s(N);
    rep(i,N) cin>>s[i];
    ll ans=0;

    rep1(C,N-1){
        if((N-1)%C==0){
            ll i=0;
            ll tmp=0;
            ll tmpans=0;
            while(N-1-i*C>i*C){
                tmp+=s[N-1-i*C]+s[i*C];
                chmax(tmpans,tmp);
                i++;
            }
            chmax(ans,tmpans);
        }
        else{
            ll tmp=0;
            ll tmpans=0;
            ll x=(N-1-C)/C;
            rep1(i,x){
                tmp+=s[i*C];
                tmp+=s[N-1-i*C];
                chmax(tmpans,tmp);
            }
            chmax(ans,tmpans);
        }
    }
    cout<<ans;
}