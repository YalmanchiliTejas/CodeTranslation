#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui inv(ui a) {
        ll t=0,nt=1,r=N,nr=a;
        while(nr) { ll q=r/nr; t-=q*nt; swap(t,nt); r-=q*nr; swap(r,nr); }
        assert(r<=1); return (t<0) ? t+N : t;
    }
public:
    inline Field(int x = 0) : v(x) {}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; } 
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {return {-v};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) { return o.v==v; }
    inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]/i;}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

int main(int,char**) {
    ios_base::sync_with_stdio(false);


    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    vector<FieldMod> E(N+1, 0), F(N+1, 0);
    
    auto f = FieldMod::fact(N);
    auto fi = FieldMod::invfact(N);
    vector<vector<FieldMod>> fip(N+1, vector<FieldMod>(N+1));
    for (int i = 0; i <= N; i++) {
        fip[i][0] = 1;
        for (int j = 1; j <= N; j++) {
            fip[i][j] = fip[i][j-1] * fi[i];
        }
    }

    E[0] = 1; F[0] = 1;
    for (int i = A; i <= B; i++) {
        for (int j = C; j <= D; j++) {
            if (j*i > N) break;

            for (int k = 0; k+j*i <= N; k++) {
                FieldMod comb = f[N-k] * fi[N-k-i*j] * fip[i][j] * fi[j];
                F[k+j*i] += E[k] * comb;
            }
        }

        E = F;
    }

    cout << E[N] << endl;
    
}
