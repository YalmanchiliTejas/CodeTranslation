#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    ll N,X,M;
    cin>>N>>X>>M;
    map<ll,bool> done;
    vector<ll> v;
    v.push_back(X%M);
    done[X%M] = true;
    while(true){
        ll t = *v.rbegin();
        if(done[(t*t)%M]) {
            v.push_back((t*t)%M);
            break;
        }
        else{
            v.push_back((t*t)%M);
            done[(t*t)%M] = true;
        }
    }
    ll ans = 0;
    ll t = *v.rbegin();
    ll p = 0;
    rep(i,v.size()){
        if(v[i] == t) {
            p = i;
            break;
        }
    }
    rep(i,p) ans += v[i];
    ll loop = v.size() - p - 1;
    ll loopsum = 0;
    for(int i = p; i < (int)v.size() - 1; i++) loopsum += v[i];
    ans += ((N-p)/loop)*loopsum;
    rep(i,(N-p)%loop){
        ans += v[p+i];
    }
    cout<<ans<<endl;
}