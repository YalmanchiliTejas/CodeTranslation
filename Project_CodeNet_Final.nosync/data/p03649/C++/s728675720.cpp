#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debugm(m) {printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}}
#define debuga(m,w) {printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,w,h) {printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}}
#define debugaar(m,w,h) {printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0;cnt<(l);++cnt)
#define iterate(cnt,b,e) for(auto cnt=(b);cnt!=(e);++cnt)
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
template<typename T1, typename T2>
ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }

mt19937 mt(8901016);
inline int rand_int(int l, int h) {
    return uniform_int_distribution<>(l, h)(mt);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiablechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiablechar(cc); cc = getchar_unlocked());
            for (; isvisiablechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
}
MaiScanner scanner;

template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lcm(T a, T b) { return a * b / gcd(a, b); }

template<typename iterator> inline size_t argmin(iterator begin, iterator end) {
    return distance(begin, min_element(begin, end));
}
template<typename iterator> inline size_t argmax(iterator begin, iterator end) {
    return distance(begin, max_element(begin, end));
}

template<typename iterator, typename T, typename F>
T reduce(iterator begin, iterator end, T init, F func) {
    T sum = init;
    for (; begin != end; ++begin)
        if (!func(sum, *begin)) break;
    return sum;
}


class Graph {
public:
    size_t n;
    vector<vector<int>> vertex_to;

    Graph(size_t n) :n(n), vertex_to(n) {}

    void connect(int from, int to) {
        vertex_to[from].emplace_back(to);
        vertex_to[to].emplace_back(from);
    }
    void resize(size_t _n) {
        n = _n;
        vertex_to.resize(_n);
    }
};


ll n, m, kei;

ll aa[100];

void ok() {
    cout << "POSSIBLE" << endl;
    exit(0);
}


bool satisfied() {
    repeat(i, n) {
        if (aa[i] >= n)
            return false;
    }
    return true;
}


int main() {

    scanner >> n;
    repeat(i, n) {
        scanner >> aa[i];
    }

    ll count = 0;
    while (!satisfied()) {

        repeat(i, n) {
            if (aa[i] < n) continue;
            ll k = aa[i] / n;
            aa[i] -= n*k;
            count += k;
            repeat(j, n) {
                if (i == j) continue;
                aa[j] += k;
            }
        }
    }

    cout << count << endl;

    return 0;
}