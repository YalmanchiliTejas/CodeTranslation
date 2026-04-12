#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;
    int ret = Inf;
    for(int i = 0;i <= max(X,Y);i++) {
        int cnt = C * i;
        int x = max(0,X - i);
        int y = max(0,Y - i);
        ret = min(ret,cnt + x * A + y * B);
    }
    cout << ret << endl;
}