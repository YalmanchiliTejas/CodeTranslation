#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int _i=(first);_i<(last);++_i){cout<<#a<<"["<<_i<<"] = "<<(a)[_i]<<endl;}
#define PRINTI(a,i)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<#i<<"] = "<<#a<<"["<<(i)<<"] = "<<(a)[i]<<endl;
#define dprintf(...) printf(__VA_ARGS__)
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#define PRINTI(a,i)
#define dprintf(...)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define MOD 1000000007
//#define MOD 998244353

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

template <class T, class U>
std::ostream& operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template <class T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";
	for (int i = 0; i < v.size(); ++i) {
        if (i) {
            if (i % 5 == 0) {
                os << ",\n ";
            } else {
                os << ", ";
            }
        }
		os << v[i];
	}
	os << "]";
	return os;
}

template <class T>
using vec2 = vector<vector<T>>;

template <class T>
using vec3 = vector<vector<vector<T>>>;

template <class T>
vec2<T> vec2_init(int n0, int n1, T x = 0) {
    return vec2<T>(n0, vector<T>(n1, x));
}

template <class T>
vec3<T> vec3_init(int n0, int n1, int n2, T x = 0) {
    return vec3<T>(n0, vec2_init(n1, n2, x));
}

/*
 *           U P
 *           - x
 *            ^
 *            |
 * LEFT -y <--+--> +y RIGHT
 *            |
 *            v
 *           + x
 *         D O W N
 */

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

enum {
    DOWN,
    RIGHT,
    UP,
    LEFT,
};

constexpr double inf = numeric_limits<double>::infinity();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X, M;
    cin >> N >> X >> M;
    ll result = 0;
    if (N > M) {
        vector<int> first(M, -1);
        vector<ll> S(M + 1);
        int p = 0;
        while (true) {
            if (first[X] == -1) {
                first[X] = p;
                S[p + 1] = S[p] + X;
                X = (X * X) % M;
            } else {
                ll period_sum = S[p] - S[first[X]];
                ll period = p - first[X];
                result = S[first[X]];
                N -= first[X];
                result += (N / period) * period_sum;
                N %= period;
                break;
            }
            ++p;
        }
    }
    while (N--) {
        result += X;
        X = (X * X) % M;
    }
    cout << result << endl;
    return 0;
}
