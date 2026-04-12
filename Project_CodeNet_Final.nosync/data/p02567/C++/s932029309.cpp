#include <iostream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,a) for(ll i=ll(a-1);i>=0;--i)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll MOD3 = 1e6;
const ll EPS = 1e-10;
int sgn(const double a){
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> tri;
typedef pair<long double,long double> point;
typedef complex<long double> Point;
const ll MAX = 3000;
constexpr ll nx[4] = {-1,0,1,0};
constexpr ll ny[4] = {0,1,0,-1};
template <class T>
class SegTree {
    public:
    int siz;
    vector<T> data;
    T id;
    function<T(T,T)> operation; //区間クエリ
    function<T(T,T)> update; //点更新
    // 単位元埋め
    SegTree(int n,T _id,function<T(T,T)> _operation,function<T(T,T)> _update):id(_id),operation(_operation),update(_update){
        siz = 1;
        while (siz < n){
            siz *= 2;
        }
        data = vector<T>(2*siz-1,id);
    }
    // 配列
    SegTree(int n,T _id,vector<T> &v,function<T(T,T)> _operation,function<T(T,T)> _update):id(_id),operation(_operation),update(_update){
        siz = 1;
        while (siz < n){
            siz *= 2;
        }
        data = vector<T>(2*siz-1,id);
        rep(i,n){
            data[siz-1+i] = v[i];
        }
        for (int i = siz-2;i >= 0;i--){
            data[i] = operation(data[i*2+1],data[i*2+2]);
        }
    }
    // 一点更新
    void change(int i,T x){
        i += siz-1;
        data[i] = update(data[i],x);
        while (i > 0){
            i = (i-1)/2;
            data[i] = operation(data[i*2+1],data[i*2+2]);
        }
    }
    // 区間クエリ
    T _query(int a,int b,int k,int l,int r){
        if (b <= l || r <= a) return id;
        if (a <= l && r <= b) return data[k];
        else{
            T r1 = _query(a,b,k*2+1,l,(l+r)/2);
            T r2 = _query(a,b,k*2+2,(l+r)/2,r);
            return operation(r1,r2);
        }
    }

    T query(int a,int b){
        return _query(a,b,0,0,siz);
    }
    // アクセス
    T operator[](int i){
        return data[i+siz-1];
    }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    cins(all(a));
    auto f1 = [](ll a,ll b){return max(a,b);};
    auto f2 = [](ll a,ll b){return b;};
    SegTree<ll> s(n,0,a,f1,f2);
    rep(i,q){
        ll t,x,v;
        cin >> t >> x >> v;
        if (t == 1){
            s.change(x-1,v);
        }
        else if (t == 2){
            PRINT(s.query(x-1,v));
        }
        else{
            ll l = x-2,r = n;
            while (r-l > 1){
                ll m = (l+r)/2;
                if (s.query(x-1,m+1) >= v){
                    r = m;
                }
                else{
                    l = m;
                }
            }
            PRINT(r+1);
        }
    }
}
