#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    multiset<ll> s;
    rep(i,N){
        ll a;
        cin >> a;
        auto itr=s.lower_bound(a);
        if (itr==s.begin()){
            s.insert(a);
        }
        else {
            itr--;
            s.erase(itr);
            s.insert(a);
        }
    }
    cout << s.size() << endl;
}