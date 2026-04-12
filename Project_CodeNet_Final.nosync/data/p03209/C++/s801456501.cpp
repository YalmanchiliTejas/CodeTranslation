#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
using namespace std;

ll N, X, a[51], p[51]; // a: all num, p: only p num

ll f(ll n, ll x) {
    if (x == 0){
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (x <= a[n-1] + 1) {     // B level(n-1)
        return f(n-1, x-1);
    } else if (x == a[n-1] + 2) {     // B level(n-1) P
        return p[n-1] + 1;
    } else if (x <= 2*a[n-1] + 2) {   // B level(n-1) P level(n-1)
        return p[n-1] + 1 + f(n-1, x - a[n-1] - 2);
    } else {                          // B level(n-1) P level(n-1) B
        return p[n];
    }
}

int main() {
    cin >> N >> X;
    a[0] = p[0] = 1;
    
    rep(i, N) {
        a[i+1] = a[i] * 2 + 3;
        p[i+1] = p[i] * 2 + 1;
    }
    cout << f(N, X) << endl;
    
    return 0;
}