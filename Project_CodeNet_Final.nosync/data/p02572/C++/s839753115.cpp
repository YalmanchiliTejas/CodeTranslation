#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    const int mod = 1e9+7;

    int N;
    cin >> N;
    vector<ll> as(N);
    for (int i=0; i<N; ++i) {
        cin >> as[i];
    }


    vector<ll> toSum(N);
    toSum[N-1] = as[N-1];
    for (int i=N-2; i>=0; --i) {
        toSum[i] = (as[i]%mod + toSum[i+1]%mod)%mod;
    }

    ll sumOfMultiples = 0;
    for (int i=0; i<N-1; ++i) {
        sumOfMultiples += (as[i]%mod * toSum[i+1]%mod) % mod;
        sumOfMultiples %= mod;
    }

    cout << sumOfMultiples << endl;

    return 0;
}