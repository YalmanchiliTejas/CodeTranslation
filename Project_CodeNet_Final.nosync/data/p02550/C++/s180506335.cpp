#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
typedef long long ll;

int main(){
    ll N,X,mod; cin>>N>>X>>mod;
    vector<ll> v;
    vector<ll> is(mod,0);
    ll cnt = 0;
    ll loop=0;
    rep(i,N){
        if(is[X]>0){
            loop += is[X];
            break;
        }else{
            is[X] = i+1;
            v.push_back(X);
            cnt++;
        }
        X *= X;
        X %= mod;
    }
    loop--;
    ll T = cnt - loop; //周期
    ll ans = 0;
    rep(i,min(cnt,N)){
        ans += v[i];
    }
    if(loop!=-1)
    {
    ll loopsum = 0;
    reverse(v.begin(),v.end());
    rep(i,loop){
        v.pop_back();
    }
    reverse(v.begin(),v.end());
    for(auto p : v){
        loopsum += p;
    }
    ans += ((N-loop)/T - 1)*loopsum;
    rep(i,(N-loop)%T){
        ans += v[i];
    }
    }
    cout << ans << endl;
}