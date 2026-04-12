#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf = 1.01e9;
const i64 inf64 = 4.01e18;
const double eps = 1e-9;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    const i64 mod = 1'000'000'007;

    string K;
    i64 D;
    cin >> K >> D;

    const i64 max_digit=10010;
    const i64 max_d=100;
    static i64 memo[max_digit][2][max_d];
    static bool done[max_digit][2][max_d];
    fill_n((i64*)memo,max_digit*2*max_d,0);
    fill_n((bool*)done,max_digit*2*max_d,false);

    assert(K.size()<max_digit);

    reverse(begin(K),end(K));
    while(K.size()<max_digit) K+='0';
    vector<i64> val(max_digit);
    rep(i,0,max_digit){
        val[i]=K[i]-'0';
    }

    function<i64(i64,i64,i64)> rec=[&](i64 d,i64 b,i64 r){
        if(d==-1){
            return i64(r==0?1:0);
        }

        auto& res=memo[d][b][r];
        if(done[d][b][r]) return res;
        done[d][b][r]=true;

        if(b==0){
            rep(i,0,10){
                res+=rec(d-1,0,(r+i)%D);
                res%=mod;
            }
        }else{
            rep(i,0,val[d]){
                res+=rec(d-1,0,(r+i)%D);
                res%=mod;
            }
            res+=rec(d-1,1,(r+val[d])%D);
            res%=mod;
        }

        return res;
    };

    // rec(max_digit-1,1,0)がmodの倍数のケースに注意
    cout << (rec(max_digit-1, 1, 0)-1+mod)%mod << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
