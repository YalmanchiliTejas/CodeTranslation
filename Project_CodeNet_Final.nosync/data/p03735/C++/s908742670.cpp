//ll ans = INF;
//ll f(const multiset<int> &s){
//    return max(s)-min(s);
//}
//void upd(const multiset<int> &ls, const multiset<int> &rs){
//    ll w1 = f(ls);
//    ll w2 = f(rs);
//    ans = min(ans,w1*w2);
//}
//void __(){
//    _(int,n);
//    _(vpii,a,n);
//    multiset<int> ls, rs;
//    rep(i,n){
//        if(a[i].X > a[i].Y)
//            swap(a[i].X,a[i].Y);
//        ls.insert(a[i].X);
//        rs.insert(a[i].Y);
//    }
//    sort(all(a));
//    rep(i,n){
//        int x,y;
//        tie(x,y) = a[i];
//        ls.erase(ls.find(x));
//        rs.erase(rs.find(y));
//        ls.insert(y);
//        rs.insert(x);
//        upd(ls,rs);
//    }
//    upd(ls,rs);
//    print ans;
//}
//
#include <set>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define REP_ZERO_INT(i,r) for(int i = 0; i < r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define X first
#define Y second
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const ll INF = ll(2e18) + 666;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
template <typename F, typename S> static
istream& operator>>(istream& stream, pair<F, S>& t){
    return stream >> t.first >> t.second;
}
T1 istream& read(T, T, istream& = cin);
T1 istream& operator>>(istream& stream, vector<T>& t){
    return read(all(t), stream);
}
T1 istream& read(T b, T e, istream& stream){
    for(T it = b; it != e; ++it)
        stream >> *it;
    return stream;
}
T1 T max(const multiset<T>& s){
    assert(!s.empty());
    return *--s.end();
}
T1 T min(const multiset<T>& s){
    assert(!s.empty());
    return *s.begin();
}
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout)
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }
    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};
#define print _print(),
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define _IWI(type,name,...) type name(__VA_ARGS__); cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
ll ans = INF;
ll f(const multiset<int> &s){
    return max(s)-min(s);
}
void upd(const multiset<int> &ls, const multiset<int> &rs){
    ll w1 = f(ls);
    ll w2 = f(rs);
    ans = min(ans,w1*w2);
}
void __(){
    _(int,n);
    _(vpii,a,n);
    multiset<int> ls, rs;
    rep(i,n){
        if(a[i].X > a[i].Y)
            swap(a[i].X,a[i].Y);
        ls.insert(a[i].X);
        rs.insert(a[i].Y);
    }
    sort(all(a));
    rep(i,n){
        int x,y;
        tie(x,y) = a[i];
        ls.erase(ls.find(x));
        rs.erase(rs.find(y));
        ls.insert(y);
        rs.insert(x);
        upd(ls,rs);
    }
    upd(ls,rs);
    print ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}
