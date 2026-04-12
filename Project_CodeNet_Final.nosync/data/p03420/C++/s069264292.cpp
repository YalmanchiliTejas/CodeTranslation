//void __(){
//    ll n,k;
//    cin >> n >> k;
//    ll ans = 0;
//    rep(mod,k+1,n){
//        rep(times,0,n/mod){
//            ll lo = times*mod+k;
//            lo = max(lo,1ll);
//            ll hi = (times+1)*mod-1;
//            hi = min(hi,n);
//            if(lo > hi)
//                continue;
//            ans += hi-lo+1;
//        }
//    }
//    print ans;
//}
//
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define REP_INT(i,l,r) for(int i = l; i <= r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
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
void __(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    rep(mod,k+1,n){
        rep(times,0,n/mod){
            ll lo = times*mod+k;
            lo = max(lo,1ll);
            ll hi = (times+1)*mod-1;
            hi = min(hi,n);
            if(lo > hi)
                continue;
            ans += hi-lo+1;
        }
    }
    print ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}
