#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    ll ans = 0;
    for(int i=0; i<N-1; i++) {
        sum -= A[i];
        ans += (A[i]) * (sum % (1000000000+7));
        ans %= (1000000000+7);
    }
    cout << ans % (1000000000+7) << endl;
}