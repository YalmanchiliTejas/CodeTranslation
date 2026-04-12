#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> add(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = N - 1; i >= 0; i--){
        add[i] = (i == N - 1 ? A[i] : add[i + 1] + A[i]);
        add[i] %= 1000000007;
    }
    ll ans = 0;
    for(int i = 0; i < N - 1; i++){
        ans += (A[i] * add[i + 1]) % 1000000007;
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}