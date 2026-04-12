#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

#define INIT std::cin.tie(0);std::ios::sync_with_stdio(false);
#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define FOR(i, s, n) for (int i = s; i < static_cast<int>(n); i++)
#define ASC(t) [](t& x, t& y){ return x < y; }
#define DESC(t) [](t& x, t& y){ return x > y; }
#define PSORT(s,p,e) partial_sort((s), next((s), (p)), (e))
#define VIEW(v,t) for_each((v).begin(), (v).end(), [](t& a) { cout << a << " "; }); cout << endl;

#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T& x, const T y){return x=(x<y)?y:x;}
template<class T> inline T CHMIN(T& x, const T y){return x=(x>y)?y:x;}
#define OUT(dist) std::cout<<(dist);
#define WS std::cout<<" ";
#define NL std::cout<<"\n"

using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using LL = long long;
using ULL = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T, int W=255> using A = array<T, W>;
template<class T, int W=255, int H=255> using A2 = array<array<T, W>, W>;

// ---
template<class T, T P=1000000007>
struct ModuloP {
    T x;
    ModuloP() : x(0) {}
    ModuloP(T y) { x = y%P; if(x < 0) x += P; }
    ModuloP operator+(const ModuloP y) { return (ModuloP(x)+=y); }
    ModuloP operator*(const ModuloP y) { return (ModuloP(x)*=y); }
    ModuloP operator-(const ModuloP y) { return (ModuloP(x)-=y); }
    ModuloP operator/(const ModuloP y) { return (ModuloP(x)/=y); }
    ModuloP operator-() { return (x == 0) ? ModuloP(P-x) : ModuloP(x); }
    ModuloP& operator+=(const ModuloP y) { x+=y.x; if(x>=P)x-=P; return *this; }
    ModuloP& operator*=(const ModuloP y) { x=((LL)x*(LL)y.x)%P; return *this; }
    ModuloP& operator-=(const ModuloP y) { x+=P-y.x; if(x>=P)x-=P; return *this; }
    ModuloP& operator/=(ModuloP y) { return ((*this)*=y.fermetinv()); }
    bool operator==(const ModuloP y) { return x == y.x; }
    bool operator!=(const ModuloP y) { return x != y.x; }
    bool operator <(const ModuloP y) { return x < y.x; }
    bool operator <=(const ModuloP y) { return x <= y.x; }
    bool operator >(const ModuloP y) { return x > y.x; }
    bool operator >=(const ModuloP y) { return x >= y.x; }

    ModuloP pow(LL n) { // O(log n)
        ModuloP ans(1), t(x);
        while(n) {
            if(n & 1) ans *= t;
            t *= t; n >>= 1;
        }
        return ans;
    }

    ModuloP fermetinv() { return pow(P-2); }

    static ModuloP combination(T n, int r){
        ModuloP m(1),fr(1); REP(i,r) m*=ModuloP(n-i), fr*=ModuloP(i+1);
        return m/fr;
    }
};
using MP = ModuloP<int>;
// ---

int main(){
    INIT;
    LL n, m, k;
    cin >> n >> m >> k;
    MP ans(0);
    FOR(d,1,n) ans += MP(n-d) * MP(m) * MP(m) * MP(d);
    FOR(d,1,m) ans += MP(m-d) * MP(n) * MP(n) * MP(d);
    ans *= MP::combination(n*m-2, k-2);
    cout << ans.x;
}