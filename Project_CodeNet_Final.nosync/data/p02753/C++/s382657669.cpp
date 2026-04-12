#include <bits/stdc++.h>
using namespace std;
#define REP(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define dup(x, y) (((x) + (y)-1) / (y))
#define PI 3.14159265359
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL LLINF = 1LL << 60;
const int INF = 1 << 30;

class UnionFind {
  public:
    // rank:それぞれの木の深さ
    vector<int> rank;
    // p:ポインタ的な配列
    vector<int> p;

    UnionFind() {}
    UnionFind(int size) {
        rank.resize(size, 0);
        p.resize(size, 0);
        //最初は、全ての値は別の木に属するようにする
        //{0},{1},{2},...といった数字一つのみを持つ木が作られる
        for(int i = 0; i < size; i++) {
            makeSet(i);
        }
    };

    // ただ一つの要素xを持つ木を作成する
    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }

    // 要素xが属する木のルートノードの値を求める
    int findSet(int x) {
        // xがルートノードでないならポインタがさしている先を再帰的に探索する
        //ルートノードならreturnする
        if(x != p[x]) {
            //ここで最終的に返ってくるのはルートノードの値であるため、探索中に経由したすべてのノードのポインタはルートノードへとつながる。
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    // xとyが同じ木に属しているか判定する
    bool isSame(int x, int y) { return findSet(x) == findSet(y); }

    // xを要素に持つ木とyを要素に持つ木を統合する
    void unite(int x, int y) { link(findSet(x), findSet(y)); }

  private:
    // xを根に持つ木とyを根に持つ木を統合する
    void link(int x, int y) {
        //なるべく木が深くならないように、rankが小さい方をrankが大きい方へ統合する
        if(rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            //木の深さが同じだったらどうしても一段深くなってしまう
            if(rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};

const int MOD_NUM = 2;
// base : 9973
class RollingHash {
    vector<LL> hash[MOD_NUM];
    vector<LL> mod = {999999937LL, 1000000007LL};
    LL base = 9973;

  public:
    RollingHash(string s) { initialize(s); }

    vector<LL> getHashNum(int left, int right) {
        vector<LL> res(MOD_NUM);
        for(int i = 0; i < MOD_NUM; i++) {
            res[i] =
                ((hash[i][right] -
                  hash[i][left] * this->mpower(base, right - left, mod[i])) %
                     mod[i] +
                 mod[i]) %
                mod[i];
        }

        return res;
    }

  private:
    void initialize(string s) {
        for(int i = 0; i < MOD_NUM; i++) {
            hash[i].assign(s.size() + 1, 0);
            for(int j = 0; j < s.size(); j++) {
                hash[i][j + 1] = (hash[i][j] * base + s[j]) % mod[i];
            }
        }
    }

    LL mpower(LL x, LL n, LL mod) {
        if(n == 0) {
            return 1;
        } else if(n % 2 == 0) {
            return mpower(x * x % mod, n / 2, mod);
        } else {
            return x * mpower(x, n - 1, mod) % mod;
        }
    }
};

template <class T> inline void chmax(T &a, T b) {
    if(a < b) {
        a = b;
    }
}
template <class T> inline void chmin(T &a, T b) {
    if(a > b) {
        a = b;
    }
}
template <class T> inline T lcm(T x, T y) { return x / __gcd(x, y) * y; }
template <class T> inline void print_vector(vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <class T> inline T mpower(T x, T n) {
    if(n == 0) {
        return 1;
    } else if(n % 2 == 0) {
        return mpower(x * x % MOD, n / 2);
    } else {
        return x * mpower(x, n - 1) % MOD;
    }
}

template<class T> inline vector<T> make_divisors(T x) {
    vector<T> divisors;
    for(T i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            divisors.push_back(i);
            if(i * i != x) {
                divisors.push_back(x / i);
            }
        }
    }
    return divisors;
}

int main(void) {
    string S;
    cin >> S;

    if(S == "AAA" or S == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}