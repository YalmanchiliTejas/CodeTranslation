#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N; 
    cin >> N;

    vector<int> A(N);
    vector<ll> B(N+1, 0); //累積和
    ll mod = 1e9+7;

    for(int i=0; i<N; i++){
        cin >> A[i];
        B[i+1] = B[i] + A[i];
    }

    ll ans = 0;

    for(int i=0; i<N; i++){
        ll sum = (B[N] - B[i+1])%mod;


        ans += A[i]*sum;
        ans %= mod;
    }

    cout<<ans<<endl;
    return 0;
} 