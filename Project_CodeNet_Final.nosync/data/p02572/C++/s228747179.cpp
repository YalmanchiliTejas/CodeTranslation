#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];

    ll s = 0;
    for (int i = 0; i < N; i++) {
        s += A[i];
    }

    ll sum = 0;
    for (int i = 0; i < N - 1; i++) {
        s -= A[i];
        sum += (A[i] * (s % 1000000007LL)) % 1000000007LL;
        sum = (sum % 1000000007LL);
        
    }
    cout << sum << endl;
    return 0;
}
