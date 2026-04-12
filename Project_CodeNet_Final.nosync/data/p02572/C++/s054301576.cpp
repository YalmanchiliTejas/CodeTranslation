#include<bits/stdc++.h>
#define rep(i,n) for ( int i=0; i< (n); ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll q = 7 + 1e9;
    vector<ll> subsum(N);
    subsum[N-1] = 0;
    for( int i=N-1; i>0; --i ){
        subsum[i-1] = subsum[i] + A[i];
        subsum[i-1] %= q;
    } 
    ll ans = 0;
    for( int i=0; i<N-1; ++i){
        ans += A[i]*subsum[i];
        ans %= q;
    }
    cout << ans << endl;
    return 0;
}