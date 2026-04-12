#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

const ll M = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll s = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        s += A[i];
        s %= M;
    }

    vector<ll> pro(N);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        s -= A[i];
        if (s < 0) s += M;
        ans += A[i] * s;
        ans %= M;
    }

    cout << ans << endl;
}