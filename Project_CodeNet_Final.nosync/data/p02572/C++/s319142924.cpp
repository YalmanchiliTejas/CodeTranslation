#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define Graph vector<vector<int>>
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<
#define AA(i) cout<<i<<endl;
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;

int main(){
    int i,N; cin >> N;
    vector<ll> A(N),B(N+1,0);
    rep(i,N) cin >> A[i];
    rep(i,N){
        B[N-1-i] = (A[N-i-1] + B[N-i])%MOD;
    }
    ll ans = 0;
    rep(i,N-1){
        ans = (ans + A[i]*B[i+1] %MOD)%MOD;
    }
    AA(ans);
    return 0;
}