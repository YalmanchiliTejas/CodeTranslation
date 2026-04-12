#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


// aiはlevel iの層の厚さ
// piはlevel iのパティの数
ll a[52], p[52]; 

ll f(int N, ll X) {
    if (N == 0) {
        if (X <= 0) {
            return 0;
        } else {
            return p[0];
        }
    } else if (X <= (a[N-1] + 1)) {
        return f(N-1, X-1);
    } else if (X == (a[N-1] + 2)) {
        return f(N-1, X-1) + 1;
    } else {
        return p[N-1] + 1 + f(N-1, X-2-a[N-1]);
    }
}

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;
    ll X; cin >> X;

    a[0] = 1;
    p[0] = 1;
    repr(i, 1, 51) {
        a[i] = a[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }

    cout << f(N, X) << endl;
    return 0;
}