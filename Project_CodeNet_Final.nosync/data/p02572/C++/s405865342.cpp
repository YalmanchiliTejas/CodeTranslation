#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = pow(10,9)+7;

int main(){
    ll N, ans = 0;
    cin >> N;
    vector<ll> A(N+1), buf(N+1);
    for(int i = 1; i <= N; ++i) cin >> A[i];
    /*
    for(int i = 1; i <= N-1; ++i){
        for(int j = i+1; j <= N; ++j){
            ll buf = A[i]*A[j] % MOD;
            ans += buf;
            ans %= MOD;
        }
    }
    */
   for(int i = N-1; i >= 1; --i){
       if(i == N-1) buf[N-1] = A[N];
       else buf[i] = (buf[i+1]+A[i+1])%MOD;
   }
   for(int i = 1; i <= N-1; ++i){
       ans += (A[i]%MOD)*(buf[i]%MOD);
       ans %= MOD;
   }
    cout << ans << endl;
    return 0;
}