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

template<typename T, size_t size> void fill(T (&ary)[size], const T& val){
    fill_n((T*)ary, size, val);
}

void solve() {
    //const i64 mod = 1'000'000'007;
    i64 N;
    cin >> N;

    vector<i64> s(N);
    rep(i,0,N){
        cin >> s[i];
    }

    i64 ans=0;
    vector<i64> acc(N); // mod xでの累積和
    rep(x,1,N){
        i64 d=(N-1)%x;
        rep(i,1,N){
            i64 j=i*x+d;
            if(j>=N) break;
            acc[j]=acc[j-x]+s[j];
        }

        i64 sum=0;
        rep(k,0,N){
            i64 pk=k*x;
            if(pk>=N-1) break;

            sum+=s[pk];

            i64 a=(N-1)-pk;
            if(a<=0 or N<=a) continue;

            i64 b=a-x;
            if(b<=0 or (k>=1 and b>=a)) continue;

            if(k>=1) {
                if (pk + b >= N - 1) continue;
                if (a <= pk and b % (a - b) == 0) continue;
            }

            i64 add=acc[k*x+b]-acc[b];
            chmax(ans,sum+add);
        }
    }

    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
