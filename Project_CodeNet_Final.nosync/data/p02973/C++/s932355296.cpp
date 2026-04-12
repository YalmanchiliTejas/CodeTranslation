#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;


int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N){
        ll a; cin >> a;
        A[i] = -a;
    }

    vector<ll> dp(100010,INF);
    rep(i,N){
        *lower_bound(dp.begin(),dp.end(),A[i]+1) = A[i];
    }
    cout << lower_bound(dp.begin(),dp.end(),INF) - dp.begin() << endl;
}