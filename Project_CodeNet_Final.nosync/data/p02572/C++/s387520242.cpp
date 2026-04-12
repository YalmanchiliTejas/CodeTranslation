#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(auto &x : A) cin >> x;

    vector<ll> s(N+1, 0);
    for(int i=0; i<N; i++) s[i+1]=(s[i]+A[i])%MOD;
    ll ans=0;
    for(int i=0; i<N; i++){
        ans=(ans+A[i]*(s[N]-s[i+1])%MOD)%MOD;
    }
    if(ans < 0) ans+=MOD;
    cout << ans << endl;
    return 0;
}