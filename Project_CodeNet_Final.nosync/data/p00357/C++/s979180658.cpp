#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _overload2(_1,_2,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(ll i=a;i<b;++i)
#define _repc(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_repc,_repi,_rep)(__VA_ARGS__)
#define _rrepi(i,a,b) for(ll i=b-1;i>=a;i--)
#define _rrep(i,n) _rrepi(i,0,n)
#define _rrepc(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrepc,_rrepi,_rrep)(__VA_ARGS__)
#define sum(...) accumulate(range(__VA_ARGS__),0)
#define _range(i) (i).begin(),(i).end()
#define _rangek(i,k) (i).begin(),(i).begin()+k
#define range(...) _overload2(__VA_ARGS__,_rangek,_range)(__VA_ARGS__)
#define LINF (ll)1000000000000000000
#define MOD (ll)1000000007
#define INF (int)1000000007
#define Yes(i) out(i?"Yes":"No")
#define YES(i) out(i?"YES":"NO")
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,size) vector<type> name(size);
#define VEC(type,name,size) vector<type> name(size);in(name)
struct aaa{aaa(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);};}aaaaaaa;
inline void in() {}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec);
template<typename T,typename L>
istream& operator >> (istream& is, pair<T,L>& p);
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec);
template<typename T,typename L>
ostream& operator << (ostream& os, pair<T,L>& p);
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){for(T& x: vec) is >> x;return is;}
template<typename T,typename L>
istream& operator >> (istream& is, pair<T,L>& p){is >> p.first;is >> p.second;return is;}
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){os << vec[0];rep(i,1,vec.size()){os << ' ' << vec[i];}return os;}
template<typename T,typename L>
ostream& operator << (ostream& os, pair<T,L>& p){os << p.first << " " << p.second;return os;}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){cin>>head;in(move(tail)...);}
template <class T>
inline void out(T t){cout<<t<<'\n';}
template <class Head, class... Tail>
inline void out(Head head,Tail... tail){cout<<head<<' ';out(move(tail)...);}

int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }
int main(){
    INT(n);
    VEC(int, d, n);
    rep(i,n)d[i]/=10;
    int max=0;
    rep(i,0,n-1){
        int a=i+d[i];
        if(a>max)max=a;
        if(max<i+1){
            out("no");
            return 0;
        }
    }
    int min=n-1;
    rrep(i,1,n){
        int a=i-d[i];
        if(a<min)min=a;
        if(min>i-1){
            out("no");
            return 0;
        }
    }
    out("yes");
}














