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
    //const i64 mod = 1'000'000'007;
    i64 N;
    cin >> N;
    vector<i64> a(N);
    rep(i,0,N) cin >> a[i];

    const i64 size=3001;
    static i64 memo[size][size][2];
    static i64 done[size][size][2];
    rep(i,0,size) rep(j,0,size){
        memo[i][j][0]=-inf64;
        memo[i][j][1]=inf64;
    }
    fill_n((bool*)done,size*size*2,false);

    function<i64(i64,i64,i64)> rec=[&](i64 l,i64 r,i64 t){
        if(l>r) return i64(0);

        auto& res=memo[l][r][t];

        if(done[l][r][t]) return res;
        done[l][r][t]=true;

        if(t==0){
            chmax(res,rec(l+1,r,1-t)+a[l]);
            chmax(res,rec(l,r-1,1-t)+a[r]);
        }else{
            chmin(res,rec(l+1,r,1-t)-a[l]);
            chmin(res,rec(l,r-1,1-t)-a[r]);
        }
        return res;
    };

    cout << rec(0,N-1,0) << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
