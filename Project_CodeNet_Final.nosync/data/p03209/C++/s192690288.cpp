#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

vector<ll> BPcnt(51);
vector<ll> Pat(51);
ll solve(ll L, ll X){
    if(X==BPcnt[L]){
        return Pat[L];
    }
    if(X==1){
        return 0;
    }
    if(L==0){
        return 1;
    }
    if(X<(BPcnt[L]+1)/2){
        return solve(L-1,X-1);
    }else if(X==(BPcnt[L]+1)/2){
        return 1+solve(L-1,X-1);
    }else{
        return 1+Pat[L-1]+solve(L-1,X-BPcnt[L-1]-2);
    }
}

int main(){
    ll N,X;
    cin >> N >> X;
    BPcnt[0] = 1;
    Pat[0] = 1;
    rep(i,50){
        BPcnt[i+1] = 2*BPcnt[i] + 3;
        Pat[i+1] = 2*Pat[i] + 1;
    }
    ll ans = solve(N,X);
    cout << ans << endl;
    return 0;
}