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

constexpr int inf = 1.01e9;
constexpr i64 inf64 = 4.01e18;
constexpr double eps = 1e-9;

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

template <typename A, typename T, size_t size>
void fill(A (&ary)[size], const T &val) {
    fill((T *)ary, (T *)(ary + size), val);
}

void solve() {
    //constexpr i64 mod = 1'000'000'007;
    i64 N;
    cin >> N;
    vector<i64> A(N);
    rep(i,0,N) cin >> A[i];

    multiset<i64> st;
    rep(i,0,N){
        if(st.empty()){
            st.insert(A[i]);
            continue;
        }
        auto ub=st.lower_bound(A[i]);
            if(ub==begin(st)){
                st.insert(A[i]);

                print("B");
                continue;
            }
            auto it=ub;
            --it;
            st.erase(it);
            st.insert(A[i]);
            print("C");
    }

    cout << st.size() << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
