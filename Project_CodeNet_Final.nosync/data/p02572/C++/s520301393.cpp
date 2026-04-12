#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
const int maxn = 200005;
int N;
ll A[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }

    ll sum = 0;
    for (int i = 0; i < N-1; i++) {
        total -= A[i];
        sum += A[i] * (total % MOD);
        sum %= MOD;
    }
    cout << sum << "\n";
    return 0;
}