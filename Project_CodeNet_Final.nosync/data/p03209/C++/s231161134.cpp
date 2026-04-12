#include <iostream>
using namespace std;

typedef long long ll;
ll a[51], b[51];

ll f(int n, ll x);

int main() {
    
    int N;
    ll K;
    cin >> N >> K;

    a[0] = 1;
    b[0] = 1;
    for (int i = 1; i < 51; i++) {
        a[i] = a[i-1] * 2 + 3;
        b[i] = b[i-1] * 2 + 1;
    }

    ll ans = f(N, K);

    cout << ans << '\n';

}


ll f(int n, ll x) {
    if (n == 0) {
        if (x <= 0) return 0;
        else return 1;
    }
    else if (x <= 1 + a[n-1]) return f(n-1, x-1);
    else if (x == 2 + a[n-1]) return b[n-1] + 1;
    else if (x <= 2 + 2*a[n-1]) return b[n-1] + 1 + f(n-1, x-2-a[n-1]);
    else if (x == 3 + 2*a[n-1]) return 2 * b[n-1] + 1;
}
