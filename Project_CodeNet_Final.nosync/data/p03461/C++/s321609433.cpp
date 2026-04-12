//void __(){
//    _(int,A);
//    _(int,B);
//    vvi d(A+1,vi(B+1,MOD));
//    rep(i,1,A)
//        rep(j,1,B)
//            cin >> d[i][j];
//    int S = 1, T = 300;
//    vpii x_edges, y_edges;
//    rep(i,2,101)
//        x_edges.pb({i-1,i});
//    per(i,200,299)
//        y_edges.pb({i,i+1});
//    vvi best_c(101,vi(101,MOD));
//    vvi test(A+1,vi(B+1,MOD));
//    rep(a,0,100)
//        rep(b,0,100)
//            rep(c,0,100){
//                if(a+b+c >= 1 && a+b+c <= 100){
//                    bool ok = true;
//                    rep(i,1,A){
//                        if(!ok)break;
//                        rep(j,1,B){
//                            if(!ok)break;
//                            if(d[i][j] > i*a+j*b+c) ok = false;
//                        }
//                    }
//                    if(ok){
//                        best_c[a][b] = min(best_c[a][b],c);
//                        rep(i,1,A){
//                            rep(j,1,B){
//                                test[i][j] = min(test[i][j],i*a+j*b+c);
//                            }
//                        }
//                    }
//                }
//            }
//    if(test != d){
//        print "Impossible";
//        return;
//    }
//    print "Possible";
//    vvi other_edges;
//    rep(a,0,100)
//        rep(b,0,100)
//            if(best_c[a][b] != MOD){
//                int u = S+a;
//                int v = T-b;
//                other_edges.pb({u,v,best_c[a][b]});
//            }
//    print T,sz(x_edges)+sz(y_edges)+sz(other_edges);
//    for(auto _ : x_edges) print _.X,_.Y,'X';
//    for(auto _ : y_edges) print _.X,_.Y,'Y';
//    for(auto _ : other_edges) print _;
//    print S,T;
//
//}
//
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define pb push_back
#define REP_INT(i,l,r) for(int i = l; i <= r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define PER_INT(i,l,r) for(int i = r; i >= l; --i)
#define GET_PER_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define per(...) GET_PER_MACRO(__VA_ARGS__,PER_ANY,PER_INT,PER_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define X first
#define Y second
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const ll MOD = 1e9 + 7;
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
T1 ostream& operator<<(ostream& stream, const vector<T>& t){
    for(int i = 0; i < sz(t); ++i){
        stream << t[i];
        if(i+1 < sz(t))
            stream << ' ';
    }
    return stream;
}
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
void __(){
    _(int,A);
    _(int,B);
    vvi d(A+1,vi(B+1,MOD));
    rep(i,1,A)
        rep(j,1,B)
            cin >> d[i][j];
    int S = 1, T = 300;
    vpii x_edges, y_edges;
    rep(i,2,101)
        x_edges.pb({i-1,i});
    per(i,200,299)
        y_edges.pb({i,i+1});
    vvi best_c(101,vi(101,MOD));
    vvi test(A+1,vi(B+1,MOD));
    rep(a,0,100)
        rep(b,0,100)
            rep(c,0,100){
                if(a+b+c >= 1 && a+b+c <= 100){
                    bool ok = true;
                    rep(i,1,A){
                        if(!ok)break;
                        rep(j,1,B){
                            if(!ok)break;
                            if(d[i][j] > i*a+j*b+c) ok = false;
                        }
                    }
                    if(ok){
                        best_c[a][b] = min(best_c[a][b],c);
                        rep(i,1,A){
                            rep(j,1,B){
                                test[i][j] = min(test[i][j],i*a+j*b+c);
                            }
                        }
                    }
                }
            }
    if(test != d){
        print "Impossible";
        return;
    }
    print "Possible";
    vvi other_edges;
    rep(a,0,100)
        rep(b,0,100)
            if(best_c[a][b] != MOD){
                int u = S+a;
                int v = T-b;
                other_edges.pb({u,v,best_c[a][b]});
            }
    print T,sz(x_edges)+sz(y_edges)+sz(other_edges);
    for(auto _ : x_edges) print _.X,_.Y,'X';
    for(auto _ : y_edges) print _.X,_.Y,'Y';
    for(auto _ : other_edges) print _;
    print S,T;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}
