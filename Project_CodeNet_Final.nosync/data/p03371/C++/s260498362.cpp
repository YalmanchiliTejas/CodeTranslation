#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <set>
#include <queue>
#include <bitset>


using namespace std;


long long dp[3][100100] = {};
const long long INF = 1LL << 60;
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define dump(a) cout << a << endl;
#define REP(n,i) for(int i = 0 ;i < n; i++)
#define pll pair<Int,Int>

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// mod. m での a の逆元 a^{-1} を計算する

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

/**
* @fn
* 最大値を取ります.Vector<int>を渡すこと.
*/
long long int imax(vector<int> a) {
    int MAX = -10000000;
    for (int i = 0; i < a.size(); i++) {
        if (MAX < a.at(i)) MAX = a.at(i);
    }
    return MAX;
}

/**
* @fn
* 最小値を取ります.Vector<int>を渡すこと.
*/
long long int imin(vector<int> a) {
    int MIN = 1000000000;
    for (int i = 0; i < a.size(); i++) {
        if (MIN > a.at(i)) MIN = a.at(i);
    }
    return MIN;
}

/**
* @fn
* 自然数について、桁数を求める
*/
Int getDigit(Int num) {
    return (Int) (log10(num)) + 1;
}


int get2Digit(Int num) {
    int cnt = 0;
    while (num > 0) {
        if (num % 2 != 0) {
            return cnt;
        }
        cnt++;
        num /= 2;
    }
    return cnt;
}

long long int absmin(vector<int> a, long long int b) {
    int mini = 100000000;
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        if (mini > abs(a.at(i) - b)) {
            mini = abs(a.at(i) - b);
            d = i;
        }
    }
    return d;
}


long long int absmax(vector<int> a, long long int b) {
    int max = -100000000;
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        if (max < abs(a.at(i) - b)) {
            max = abs(a.at(i) - b);
            d = i;
        }
    }
    return d;
}

Int gcd(Int a, Int b) {
    if (a < b) swap(a, b);
    if (b < 1) return -1;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void haerobatya(int start, int end, char level) {
    if (start > end) swap(start, end);
    for (int i = start; i <= end; i++) {
        if (i < 100) {
            cout << "https://atcoder.jp/contests/abc0" << i << "/tasks/abc0" << i << "_" << level << endl;
        } else {
            cout << "https://atcoder.jp/contests/abc" << i << "/tasks/abc" << i << "_" << level << endl;
        }
    }
}

long long int cntmod(long long int warareru, long long int mod) {
    long long int i = 0;
    for (i = 0; true; i++) {
        if (warareru % mod == 0 && warareru >= mod) {
            warareru /= mod;
        } else {
            return i;
        }
    }
}

void ansYes(bool a) {
    if (a) cout << "Yes" << endl;
    else cout << "No" << endl;
}

void ansYES(bool a) {
    if (a) cout << "YES" << endl;
    else cout << "NO" << endl;
}


Int euclidean_gcd(Int a, Int b) {
    while (true) {
        if (a < b) swap(a, b);
        if (!b) break;
    }
    return a;
}

//UnionFind群
class UnionFind {
protected:
    vector<int> par;
    vector<int> data;
    int cnt;
public:
    UnionFind() : par(1), data(1), cnt(1) {};

    UnionFind(int N);

    UnionFind(const vector<int> &par, const vector<int> &data, int cnt);

    int root(int x);

    int marge(int x, int y);

    bool same(int x, int y);

    int add();

    int add(int x);

    inline int getSize(int x) { return data.at(root(x)); };

    int allroot();

    inline bool isroot(int x) { return (par.at(x) == -1); };
};


UnionFind::UnionFind(int N) : par(N), data(N), cnt(N) {
    for (int i = 0; i < N; i++) {
        par.at(i) = -1;
        data.at(i) = 1;
    }
}


int UnionFind::root(int x) {
    if (par.at(x) == -1) return x;
    return par.at(x) = root(par.at(x)); // 経路圧縮
}


int UnionFind::marge(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return rx;
    else { // ノード数の少ない方に接続
        if (data.at(rx) < data.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        data.at(rx) += data.at(ry);
        return rx;
    }
}

bool UnionFind::same(int x, int y) {
    return root(x) == root(y);
}

int UnionFind::add() {
    par.push_back(cnt);
    cnt++;
    return cnt - 1;
}

int UnionFind::add(int x) {
    par.push_back(cnt);
    cnt++;
    return marge(x, cnt);
}

int UnionFind::allroot() {
    int cnt = 0;
    for (const auto it : par) {
        if (it == -1) cnt++;
    }
    return cnt;
}


//約数の数を数える
int yakusu(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

int vecsum(vector<int> a) {
    int res = 0;
    for (auto z : a){
        res += z;
    }
    return res;
}

vector<int> yakusurekkyo(int n) {
    vector<int> a;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n) a.push_back(n / i);
        }
    }
    return a;
}


bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


vector<long long int> Prime;
void Eratosthenes(long long int n) {
    vector<bool> is_prime(n, true);
    for (int i = 2; i * i <= n; i++) { ;
        if (is_prime.at(i)) {
            for (int j = i + i; j < n; j += i) {
                is_prime.at(j) = false;
            }
        }
    }


    for (int i = 2;i < n;i++) {
        if (is_prime.at(i)){
            Prime.emplace_back(i);
        }
    }
}

struct node{
    Int to;
    Int length;
};

class Graph {
protected:
    int n;
    vector<Int> prev;
    vector<Int> minD;
    vector<vector<node>> ker;
public:
    Graph(Int N) : n(N), prev(N), minD(N), ker(N) {}

    void addEdge(Int from, Int next, Int cost) {
        ker.at(from).push_back({next, cost});
        ker.at(next).push_back({from, cost});
    }

    void addDirectedEdge(Int from, Int next, Int cost) {
        ker.at(from).push_back({next, cost});
    }

    void dijkstra(Int s) {
        REP(n, i) {
            minD.at(i) = INF;
        }
        minD.at(s) = 0;
        priority_queue<pll, vector<pll >, greater<>> que;
        que.push({0, s});
        while (!que.empty()) {
            auto z = que.top();
            que.pop();
            int v = z.second;
            if (minD[v] < z.first) continue;
            REP(ker.at(v).size(), i) {
                node n = ker.at(v).at(i);
                if (minD[n.to] > minD[v] + n.length) {
                    minD[n.to] = minD[v] + n.length;
                    que.push({minD[n.to], n.to});
                }
            }
        }
    }

    bool bellmanford(Int s) {
        bool flag = false;
        REP(n, i) {
            minD.at(i) = INF;
        }
        minD.at(s) = 0;
        REP(n - 1, i) {
            REP(n, k) {
                for (auto z: ker.at(k)) {
                    if (minD[k] != INF && minD[z.to] > minD[k] + z.length) {
                        minD[z.to] = minD[k] + z.length;
                    }
                }
            }
        }
        REP(n, k) {
            for (auto z: ker.at(k)) {
                if (minD[k] != INF && minD[z.to] > minD[k] + z.length) {
                    minD[z.to] = minD[k] + z.length;
                    flag = true;
                }
            }
        }
        return flag;
    }

    Int getD(Int x) {
        return minD[x];
    }
    Int put(Int x){
        if (minD[x] == INF) {
            cout << "INF" << endl;
        }else{
            cout << minD[x] << endl;
        }
        return minD[x];
    }
};
int main() {
    Int a,b,c;
    cin >> a >> b >> c;
    Int x ,y;
    cin >> x >> y;
    Int ans = 0;
    if (a + b < 2 * c) {
        ans += a * x + b * y;
    }else {
        ans += min(x, y) * c * 2;
        if (x > y) {
            if (c * 2 < a) {
                ans += (x - y) * 2 * c;
            } else {
                ans += (x - y) * a;
            }
        } else {
            if (c * 2 < b) {
                ans += (y - x) * 2 * c;
            } else {
                ans += (y - x) * b;
            }
        }
    }
    cout << ans << endl;
}