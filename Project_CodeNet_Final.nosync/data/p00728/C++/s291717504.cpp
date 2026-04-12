#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
const double pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define vi vector<int>
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    REP(i,v.size()){if(i)os<<" ";os<<v[i];}return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    REP(i,v.size()){if(i)os<<endl;os<<v[i];}return os;}

const int MOD = 1e9 + 7;
const int INF = 1 << 30;


class UnionFind{
private:
        vector<int> par,rank,sizes;
        int tree;

public:
        explicit UnionFind(const int n) : tree(n){
            par.resize(n+1);
            rank.resize(n+1);
            sizes.resize(n+1);
            rep(i,n){
                par[i] = i;
                sizes[i] = 1;
            }
        }

        ~UnionFind() = default;

        int root(int x){
            if(par[x] == x) return x;
            else return par[x] = root(par[x]);
        }

        int find(int x){ return root(x);}

        void unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x == y) return;

            if (rank[x] < rank[y]) swap(x, y);
            par[y] = x;
            tree--;
            sizes[x] += sizes[y];
            if (rank[x] == rank[y]) rank[x]++;
        }

        bool same(int x, int y){
            return root(x) == root(y);
        }

        int size(int x){
            return sizes[x];
        }

        int sumTree(){
            return tree;
        }
};

template <typename T>
class segmentTree{
private:
    int n;
    vector<T> arr;
public:

    explicit segmentTree(vector<T> v){
        ll sz = v.size();
        //while()

        arr.resize(2*n - 1);

    }

    T &operator[](int n){ return arr[n];}


};

template <int mod>
class ModInt{
private:
    ll _num;

public:
    ModInt(){_num = 0;}
    explicit ModInt(ll value){_num = value%mod;}

    ModInt operator+(ModInt &x){ return ModInt(_num + x._num);}
    ModInt operator-(ModInt &x){ return ModInt(_num - x._num);}
    ModInt operator*(ModInt &x){ return ModInt(_num * x._num);}
    friend ostream &operator<<(ostream &os, const ModInt &x){os<<x._num; return os;}
    friend istream &operator>>(istream &is, ModInt &x){is>>x._num; return is;}
};
using mint = ModInt<MOD>;


class topos{

};

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

ll power(ll m, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = ((res%mod) * (m%mod))%mod;
        m = (m * m)%mod;
        n >>= 1;
    }
    return res;
}


int main() {
    while(true){
        int n; cin >> n;

        if(n == 0) break;

        vi a(n);
        rep(i,n){
            cin >> a[i];
        }

        sort(a.begin(),a.end());

        int sum = 0;
        rep(i,n-2){
            sum += a[i+1];
        }
        
        cout << sum/(n-2) << endl;
    }

}
