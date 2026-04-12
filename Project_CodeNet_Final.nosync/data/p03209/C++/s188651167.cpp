#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N = in<ll>(),X = in<ll>();
    vector<ll> tpow(N+3);
    tpow[0] = 1;
    REP(i,N+2)tpow[i+1] = 2*tpow[i];
    ll answer = 0;
    for (ll i = N; i >= 0; i--){
        if(tpow[i+1]-2 >= X){
            X--;
            if(X < 0)X = 0;
        }else if(tpow[i+1] - 1 <= X){
            answer += tpow[i];
            X-= tpow[i+1] - 1;
        }
    }
    cout << answer << "\n";
}