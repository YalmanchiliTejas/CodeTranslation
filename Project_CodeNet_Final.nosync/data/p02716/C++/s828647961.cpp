#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll ans = 0;
    if (N % 2 == 0){
        vector<ll> dp1(N + 1, 0);
        vector<ll> dp2(N + 1, 0);
        dp1[0] = A[0];
        dp2[1] = A[1];
        for (ll i = 2; i < N; i += 2){
            dp1[i] = dp1[i - 2] + A[i];
        }
        for (ll i = 3; i < N; i += 2){
            dp2[i] = max(dp2[i - 2] + A[i], dp1[i - 3] + A[i]);
        }
        ans = max(dp1[N - 2], dp2[N - 1]);
    }
    else{
        vector<ll> dp1(N + 1, 0);
        vector<ll> dp2(N + 1, 0);
        vector<ll> dp3(N + 1, 0);
        dp1[0] = A[0];
        dp2[1] = A[1];
        dp3[2] = A[2];
        for (ll i = 2; i < N; i += 2){
            dp1[i] = dp1[i - 2] + A[i];
        }
        for (ll i = 3; i < N; i += 2){
            dp2[i] = max(dp1[i - 3] + A[i], dp2[i - 2] + A[i]);
        }
        for (ll i = 4; i < N; i += 2){
            dp3[i] = max(dp1[i - 4] + A[i], max(dp2[i - 3] + A[i], dp3[i - 2] + A[i]));
        }
        ans = max(dp1[N - 3], max(dp2[N - 2], dp3[N - 1]));
        
    }
    cout << ans << endl;
}
