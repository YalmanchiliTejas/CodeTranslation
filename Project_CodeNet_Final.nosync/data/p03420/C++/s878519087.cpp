#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll N,K;
    cin>>N>>K;
    ll ans = 0;
    for(ll i = K+1; i <= N; i++){
        ll t = ((N-K)/i);
        ll s = t*(i-K);
        s+=min(N+1,(t+1)*i)-(K+t*i);
      	if(K==0) s--;
        ans+=s;
    }
    cout<<ans<<endl;
}