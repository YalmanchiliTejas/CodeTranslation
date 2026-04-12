#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int64)1e9
#define REP(i, n) for(int64 i = 0; i < (n); i++)
#define FOR(i, a, b) for(int64 i = (a); i < (b); i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using int64 = int_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

template<typename A, typename B> inline void chmin(A &a, B b) { if(a > b) a = b; }
template<typename A, typename B> inline void chmax(A &a, B b) { if(a < b) a = b; }

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
    for(auto &e:u) fill_v<T>(e,v...);
}

int64 query(int64 a, int64 b) {
    cout << "? " << a+1 << " " << b+1 << endl;
    int64 x;
    cin >> x;
    return x;
}

vector<int64> res;

void ans() {
    cout << "! ";
    REP(i, res.size())
        cout << res[i]+1 << " ";
    cout << endl;
}

int main(void){
    int64 N, s, t;
    cin >> N >> s >> t; s--; t--;
    int64 dist = query(s, t);
    vector<PLL> vs;
    REP(i, N) {
        int64 d1 = query(s, i), d2 = query(i, t);
        if (d1 + d2 == dist) {
            vs.push_back(PLL(d1, i));
        }
    }
    sort(all(vs));
    int64 now = 0, v = s;
    int64 p = 0;
    while (p < vs.size() && v != t) {
//        cout << v << " " << p << " " << now << " " << vs[p].fs << endl;
        if (query(v, vs[p].sc) == vs[p].fs-now) {
            res.push_back(vs[p].sc);
            v = vs[p].sc;
            now = vs[p].fs;
        }
        p++;
    }
    ans();
}
