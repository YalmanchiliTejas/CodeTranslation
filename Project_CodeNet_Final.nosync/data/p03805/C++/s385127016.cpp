#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <functional>
#include <queue>
#include <tuple>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using ll = long long;
using vll = vector<ll>;
using pii = pair<int, int>;
using vb = vector<char>;
using vvb = vector<vb>;

#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define mp(a, b) make_pair(a,b)

#define fi first
#define sn second
#define decpii(p) p.fi--,p.sn--;


#ifdef LOCAL
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define dumpn(c) cerr << "> " << #c << " = " << (c) << ", ";
#else
#define dump(c) ;
#define dumpn(c) ;
#endif


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    rep(i, (int) a.size())os << (i ? " " : "") << a[i];
    return os << ']';
}


int dxf[] = {1, 0, -1, 0};
int dyf[] = {0, -1, 0, 1};

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

inline vi uni(vi &vec) {
    sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

struct ____ {
    ____() {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} ________;

int solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        --a[i],--b[i];
    }

    vi nlist(N);
    iota(all(nlist), 0);
    int res = 0;
    do {
        if(nlist[0] != 0)
            continue;

        REP(t, 1, N) {
            bool ok = false;
            rep(i, M) {
                if ((a[i] == nlist[t - 1] && b[i] == nlist[t]) ||
                    (b[i] == nlist[t - 1] && a[i] == nlist[t])) {
                    ok = true;
                }
            }
            if (!ok) {
                break;
            }

            if (t == N - 1)
                res++;
        }
    } while (next_permutation(all(nlist)));

    return res;
}

int main() {
    cout << solve() << endl;
    return 0;
}
