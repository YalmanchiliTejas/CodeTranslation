#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(s,i,n) for(int i=s;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define skip(i,n,p) for(int i=0;i<n;i+=p)
#define all(a)  (a).begin(),(a).end()
#define int64 long long
#define debug cout << __FILE__ << ":" << __LINE__ << endl;

struct Init {
    Init() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.precision(20);
        cout << fixed;
    }
} init;

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    for(int i = 0; i < (int) v.size(); i++) {
        ostr << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return ostr;
}

int64 gcd(int64 a, int64 b) {
    if (a < b) a, b = b, a;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int64 modinv(int64 a, int64 m) {
    int64 b = m, u = 1, v = 0;
    while (b) {
        int64 t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    int64 N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        exit(0);
    }

    int64 ans = 0;
    reps(1, j, N+1) {
        if (j <= K) continue;
        int64 t = N / j;
        ans += (j - K) * t;
        if (N % j >= K) ans += N % j - K + 1;
    }

    cout << ans << endl;
}
