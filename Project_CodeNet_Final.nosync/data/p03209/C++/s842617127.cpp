#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

/* modつき二分累乗法 */
ll modpow(ll a, ll b) {
    ll res = 1;
    for (a = a; b; a = a * a , b >>= 1){
        if (b & 1) res = res * a;
    }
    return res;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N = in<ll>(), X = in<ll>();
    ll answer = 0;
    RREP(i,N+1){
        if(X >= modpow(2,i+1)-1){
            answer += modpow(2,i);
            X -= modpow(2,i+1)-2;
        }
        X--;
    }
    cout << answer << "\n";
}