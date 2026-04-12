#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }

static const LL MOD = 1e+9 + 7;

struct ModInt{
    static const LL MOD = 1e+9 + 7;
    LL v;
    ModInt():v(0){}
    ModInt(LL op):v(op){}
    ModInt operator+(ModInt op) const{ return (v + op) % MOD; }
    ModInt operator-(ModInt op) const{ return (v - op + MOD) % MOD; }
    ModInt operator*(ModInt op) const{ return (v * op) % MOD; }
    ModInt operator/(ModInt op) const{ return (v * op.inverse()) % MOD; }
    ModInt operator%(LL op) = delete;
    ModInt operator+=(ModInt op){ return v = (v + op) % MOD; }
    ModInt operator-=(ModInt op){ return v = (v - op + MOD) % MOD; }
    ModInt operator*=(ModInt op){ return v = (v * op) % MOD; }
    ModInt operator/=(ModInt op){ return v = (v * op.inverse()) % MOD; }
    ModInt operator-() const{ return MOD - v; }
    bool operator==(ModInt op) const{ return v == op.v; }
    bool operator!=(ModInt op) const{ return v != op.v; }
    ModInt inverse() const{ return pow(MOD-2); }
    ModInt pow(LL n) const{
        if(n < 0) return pow(MOD-1 + n);
        if(n == 0) return 1;
        ModInt res = pow(n/2);
        return res * res * ((n&1)?ModInt(v): ModInt(1));
    }
    LL get() const{ return v; }
private:
    operator LL() const{ return v; }
};
istream& operator>>(istream& st, ModInt& m){ st>>m.v; return st; }
ostream& operator<<(ostream& st, const ModInt& m){ st<<m.v; return st; }


vector<ModInt> factorial(LL n){
    vector<ModInt> res(n, 1);
    for(LL i = 2; i < n; ++i) res[i] = res[i-1] * ModInt(i);
    return res;
}

ModInt permutation(LL n, LL m, vector<ModInt>& factorial){
    if(m < 0 || n < m) return 0;
    if(m == 0) return 1;
    return factorial.at(n) / factorial.at(n-m);
}

ModInt combination(LL n, LL m, vector<ModInt>& factorial){
    if(m < 0 || n < m) return 0;
    if(m == 0) return 1;
    return factorial.at(n) / factorial.at(n-m) / factorial.at(m);
}


int main(){
    LL n, m, k;
    cin >> n >> m >> k;
    LL n_cell = n*m;
    vector<ModInt> f = factorial(n_cell+1);
    ModInt cnt = combination(n_cell-2, k-2, f);
    LL cost1 = 0;
    for(LL i = 1; i < n; ++i){
        cost1 = (cost1 + i * (n-i) % MOD * (m * m % MOD) % MOD) % MOD;
    }
    LL cost2 = 0;
    for(LL i = 1; i < m; ++i){
        cost2 = (cost2 + i * (m-i) % MOD * (n * n % MOD) % MOD) % MOD;
    }
    LL cost = (cost1 + cost2) % MOD;
    cerr << "cnt=" << cnt.get() << endl;
    cerr << "cost=" << cost << endl;
    ModInt ans = cnt * ModInt(cost);
    cout << ans.get() << endl;
    return 0;
}


