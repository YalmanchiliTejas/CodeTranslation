#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}}; ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
/*!* [modint] *!*/
/*+* 剰余環整数 *+*/
struct int_m;
int_m invmod(int_m);
int_m powmod(int_m, i64);
struct int_m {
    static i64 m;
    i64 v;
    int_m() {}
    int_m(i64 x) { v = (x % m + m) % m; }
    int_m operator+(const int_m &y) const { return v + y.v > m ? v + y.v - m : v + y.v; }
    int_m operator-(const int_m &y) const { return v - y.v < 0 ? v - y.v + m : v - y.v; }
    int_m operator*(const int_m &y) const { return (v * y.v) % m; }
    bool operator==(const int_m &y) const { return v == y.v; }
    bool operator!=(const int_m &y) const { return v != y.v; }
    void operator+=(const int_m &y) { *this = *this + y; }
    void operator-=(const int_m &y) { *this = *this - y; }
    void operator*=(const int_m &y) { *this = *this * y; }
    friend istream &operator>>(istream &ist, int_m &m) { ist >> m.v; return ist; }
    friend ostream &operator<<(ostream &ost, int_m m) { ost << m.v; return ost; }
    int_m operator^(const i64   &y) const {
        int_m v = 1; int p = y;
        for (int_m b = *this; p > 0; p >>= 1, b *= b) if (p & 1) v *= b;
        return v;
    }
    void operator^=(const i64   &y) { *this = *this ^ y; }
    // for prime mod
    int_m operator/(const int_m &y) const { return *this * (y ^ (m - 2)); }
    void operator/=(const int_m &y) { *this = *this / y; }
};
i64 int_m::m;

int main() {
    int_m::m = 1e9 + 7;
    int N;
    cin >> N;
    int_m X = 0;
    int_m Y = 0;
    for(int i = 0; i < N; i++) {
        i64 A;
        cin >> A;
        X += A;
        Y += A * A;
    }
    int_m ans = (X * X - Y) / 2;
    cout << ans << endl;
    return 0;
}