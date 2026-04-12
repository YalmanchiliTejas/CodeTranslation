#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define debugv(v) printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;
#define debugm(m) printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;
#define debugaa(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}
#define debugaar(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}
#define ALL(v) (v).begin(),(v).end()
#define repeat(l) for(auto cnt=0;cnt<(l);++cnt)
#define iterate(b,e) for(auto cnt=(b);cnt!=(e);++cnt)
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
template<typename T1, typename T2>
ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }

#define TIME chrono::system_clock::now()
#define MILLISEC(t) (chrono::duration_cast<chrono::milliseconds>(t).count())
namespace {
    std::chrono::system_clock::time_point ttt;
    void tic() { ttt = TIME; }
    void toc() { fprintf(stderr, "TIME : %lldms\n", MILLISEC(TIME - ttt)); }
    std::chrono::system_clock::time_point tle = TIME;
#ifdef __MAI
    void safe_tle(int msec) { assert(MILLISEC(TIME - tle) < msec); }
#else
#define safe_tle(k) ;
#endif
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
        template<typename T>
        void input_integer(T& var) {
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
    };
}
MaiScanner scanner;



class unionfind {
public:
    vector<int> data;
    unionfind(int size) : data(size, -1) { }
    bool union_set(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    inline bool find_set(int x, int y) {
        return root(x) == root(y);
    }
    inline int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    inline int size(int x) {
        return -data[root(x)];
    }
};



// ソートしてi番目の値は idx[i]番目の値
// i番目の値は  ソートしてidxr[i]番目の値
template <typename ITER>
void sort_idx(const ITER begin, const ITER end, vector<int> &idx, vector<int> &idxr) {
    size_t n = end - begin;
    idx.resize(n);
    idxr.resize(n);
    for (int i = 0; i < n; ++i) idx[i] = i;
    sort(idx.begin(), idx.end(), [&begin](int l, int r) {return begin[l] < begin[r]; });
    for (int i = 0; i < n; ++i) idxr[idx[i]] = i;
}



int width, height;
int m, n, kei;

pair<int,int> pp[100010];

int cost(pair<int, int>& l, pair<int, int>& r) {
    return min(abs(l.first - r.first), abs(l.second - r.second));
}

int main() {
    scanner >> n;

    repeat(n) {
        int x, y;
        scanner >> x >> y;
        pp[cnt] = make_pair(x, y);
    }

    sort(pp, pp + n, [](const auto& l, const auto& r) {
        return l.second == r.second ? l.first < r.first : l.second < r.second; });

    vector<int> idx, idxr;
    
    sort_idx(pp, pp + n, idx, idxr);


    map<int, vector<pair<int, int>>> memo;

    for (int i = 1; i < n; ++i) {
        memo[cost(pp[i - 1], pp[i])].push_back(make_pair(i - 1, i));
    }

    for (int i = 1; i < n; ++i) {
        int u = idx[i];
        int v = idx[i-1];
        memo[cost(pp[v], pp[u])].push_back(make_pair(v, u));
    }

    unionfind tree(n);

    ll best = 0;
    
    for (auto& pr : memo) {
        for (auto e : pr.second) {
            int u = e.first;
            int v = e.second;
            if (!tree.find_set(u, v)) {
                tree.union_set(u, v);
                best += pr.first;
            }
        }
    }

    cout << best << endl;


    return 0;
}