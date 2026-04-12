#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
class Compress{
    int n;
    vector< pair<T, int> > zip;
    vector<T> unzip;

public:
    Compress(vector<T> dat = {}){
        build(dat);
    }

    void build(vector<T>& dat){
        zip.clear();
        unzip.clear();

        sort(dat.begin(), dat.end());
        dat.erase(unique(dat.begin(), dat.end()), dat.end());

        n = (int)dat.size();
        for(int i = 0 ; i < n ; ++i){
            zip.emplace_back(dat[i], i);
            unzip.emplace_back(dat[i]);
        }

        return;
    }

    int get(T x){
        return (*lower_bound(zip.begin(), zip.end(), make_pair(x, INT_MIN))).second;
    }

    T restore(int k){
        return unzip[k];
    }

    int size(void){
        return n;
    }
};


class UnionFind{
    vector<int> par;
    vector<long long> wei;
    int groupCount;

public:
    UnionFind(int n = 0){
        init(n);
    }

    void init(int n = 0){
        par.resize(n);
        fill(par.begin(), par.end(), -1);

        wei.resize(n);
        fill(wei.begin(), wei.end(), 0LL);

        groupCount = n;

        return;
    }

    int root(int x){
        if(par[x] < 0){
            return x;
        }
        int r = root(par[x]);
        wei[x] += wei[par[x]];
        return par[x] = r;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return -par[root(x)];
    }

    long long weight(int x){
        root(x);
        return wei[x];
    }

    long long diff(int x, int y){
        return weight(y) - weight(x);
    }

    bool unite(int x, int y, long long w = 0){
        w += weight(x) - weight(y);

        x = root(x);
        y = root(y);

        if(x == y){
            return false;
        }

        if(par[y] < par[x]){
            swap(x, y);
            w = -w;
        }

        par[x] += par[y];
        par[y] = x;
        wei[y] = w;
        --groupCount;

        return true;
    }

    int size(void){
        return groupCount;
    }
};

template<typename T>
bool chmax(T& a, T b, bool equal = false){
    if(a < b || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b, bool equal = false){
    if(b < a || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(cin >> n, n){
        vector<int> l(n), t(n), r(n), b(n);
        vector<int> xs = {-1, IINF};
        vector<int> ys = {-1, IINF};
        rep(i, n){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            l[i] <<= 1;
            ++l[i];
            t[i] <<= 1;
            r[i] <<= 1;
            b[i] <<= 1;
            ++b[i];
            xs.emplace_back(l[i]);
            xs.emplace_back(r[i]);
            ys.emplace_back(t[i]);
            ys.emplace_back(b[i]);
        }

        Compress<int> x(xs), y(ys);

        vector< vector<int> > imos(y.size() + 1, vector<int>(x.size() + 1, 0));
        rep(i, n){
            ++imos[y.get(b[i])][x.get(l[i])];
            --imos[y.get(b[i])][x.get(r[i])];
            --imos[y.get(t[i])][x.get(l[i])];
            ++imos[y.get(t[i])][x.get(r[i])];
        }

        rep(i, y.size() + 1){
            reps(j, x.size()){
                imos[i][j] += imos[i][j - 1];
            }
        }

        reps(i, y.size()){
            rep(j, x.size() + 1){
                imos[i][j] += imos[i - 1][j];
            }
        }

        UnionFind uf((y.size() + 1) * (x.size() + 1));
        rep(i, y.size() + 1){
            rep(j, x.size() + 1){
                rep(k, 4){
                    int ny = i + dy4[k];
                    int nx = j + dx4[k];
                    if(ny < 0 || y.size() < ny || nx < 0 || x.size() < nx){
                        continue;
                    }
                    if(imos[i][j] == imos[ny][nx]){
                        uf.unite(i * (x.size() + 1) + j, ny * (x.size() + 1) + nx);
                    }
                }
            }
        }

        cout << uf.size() << endl;
    }

    return 0;
}
