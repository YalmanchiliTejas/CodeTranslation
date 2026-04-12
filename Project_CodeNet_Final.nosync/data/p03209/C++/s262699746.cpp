#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<ll> h,b;
ll dfs(ll n, ll x){
    if(n == 0)return 1;
    if(x == 1)return 0;
    if(x == h[n-1] + 2)return b[n-1] + 1;
    if(x == h[n])return b[n];
    if(x < h[n-1] + 2){
        return dfs(n-1, x - 1);
    }else{
        return b[n-1] + 1 + dfs(n-1, x - h[n-1] - 2);
    }
}
main(){
    ll N,X;
    cin >> N >> X;
    h.resize(N+1);
    b.resize(N+1);
    h[0] = b[0] = 1;
    rep(i,1,N+1){
        h[i] = h[i-1] * 2 + 3;
        b[i] = b[i-1] * 2 + 1;
    }
    cout << dfs(N,X) << endl;
}