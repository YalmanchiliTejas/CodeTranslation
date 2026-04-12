#include <bits/stdc++.h>
#include <numeric>
#define ll long long
#define int ll
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


#define DEBUG

using namespace std;

const ll MOD = 998244353;
const ll INF = (ll)1000000007 * 1000000007;


#ifdef DEBUG
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
#else
#define PRINT(A)
#endif

typedef pair<int, int> P;

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll A,B,C,X,Y,N, M, K;
signed main() {

    cin >> A >> B >> C >> X >> Y;

    int combi = min(X,Y);
    int res = 0;
    if(A + B >= C*2){
        res += 2*combi * C;
        if(X > Y){
            res += (X-combi)*min(A,C*2);
        }
        else{
            res += (Y-combi)*min(B,C*2);
        }
    }
    else{
        res = X*A + Y*B;
    }
    
    cout << res << endl;
}
