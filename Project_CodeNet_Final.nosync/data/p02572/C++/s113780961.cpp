#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const ll MOD = 1e9+7;

int main(){
    int N; cin >> N;
    vector<ll> A(N),sum(N+1);
    rep(i,N){
        int a ; scanf("%d", &a);
        A[i] = a;
    }
    ll s=0;
    for(int i=N-1;i>=0;i--){
        sum[i] = sum[i+1]+A[i];
        sum[i] %= MOD;
    }

    ll res = 0;
    rep(i,N){
        res += A[i]*sum[i+1];
        res %= MOD;
    }
    cout << res << endl;
}