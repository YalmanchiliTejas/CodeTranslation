#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int x;fixprec(int d):x(d){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.x);}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
/*!* [modint] *!*/
/*+* 剰余環整数と剰余階乗 *+*/
struct int_m;
int_m invmod(int_m);
int_m powmod(int_m, i64);
struct int_m {
    static i64 m;
    i64 v;
    int_m() {}
    int_m(i64 x) : v(x) {}
    int_m operator+(const int_m &y) const { return (v + y.v) % m; }
    int_m operator-(const int_m &y) const { return (v - y.v + m) % m; }
    int_m operator*(const int_m &y) const { return (v * y.v) % m; }
    int_m operator/(const int_m &y) const { return *this * invmod(y); }
    int_m operator^(const i64   &y) const { return powmod(*this, y); }
    void operator+=(const int_m &y) { *this = *this + y; }
    void operator-=(const int_m &y) { *this = *this - y; }
    void operator*=(const int_m &y) { *this = *this * y; }
    void operator/=(const int_m &y) { *this = *this / y; }
    void operator^=(const i64   &y) { *this = *this ^ y; }
    bool operator==(const int_m &y) const { return v == y.v; }
    bool operator!=(const int_m &y) const { return v != y.v; }
    friend istream &operator>>(istream &ist, int_m m) { ist >> m.v; return ist; }
    friend ostream &operator<<(ostream &ost, int_m m) { ost << m.v; return ost; }
};
i64 int_m::m;
// O(log a)
int_m powmod(int_m a, i64 p) {
    int_m v = 1;
    for(int_m b = a; p > 0; p >>= 1, b *= b ) if(p & 1) v *= b;
    return v;
}
int_m invmod(int_m x) {
    return powmod(x, x.m - 2);
}

int main() {
    int_m::m = 998244353;
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int &a : A) cin >> a;
    vector<int_m> cur(S + 1);
    vector<int_m> prev(S + 1);
    prev[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= S; j++) {
            cur[j] += prev[j];
            if(j + A[i] > S) continue;
            int_m tmp = prev[j];
            if(j == 0) tmp *= i + 1;
            if(j + A[i] == S) tmp *= N - i;
            cur[j + A[i]] += tmp;
        }
        for(int_m &x : prev) x = 0;
        swap(prev, cur);
    }
    cout << prev[S] << endl;
    return 0;
}

