#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

int main(void) {
    char T;
    while (cin >> T && T != '#') {
        vector<int64> r[4];
        vector<char> s[4];
        REP(i, 4) {
            r[i].resize(13); s[i].resize(13);
            REP(j, 13) {
                char a;
                cin >> a >> s[i][j];
                if ('2' <= a && a <= '9') {
                    r[i][j] = a-'0';
                } else {
                    switch (a) {
                        case 'T': r[i][j] = 10; break;
                        case 'J': r[i][j] = 11; break;
                        case 'Q': r[i][j] = 12; break;
                        case 'K': r[i][j] = 13; break;
                        case 'A': r[i][j] = 14; break;
                    }
                }
            }
        }
        int64 lead = 0;
        int32 res[2] = {};
        res[0] = res[1] = 0;
        REP(i, 13) {
            char lc = s[lead][i];
            char nc = s[lead][i]; int64 rank = r[lead][i];
            int64 now = lead;
            REP(j, 4) {
                if (nc == T) {
                    if (s[j][i] == T && rank < r[j][i]) {
                        rank = r[j][i];  now = j;
                    }
                } else {
                    if (s[j][i] == T) {
                        rank = r[j][i]; now = j;
                        nc = s[j][i];
                    } else if (s[j][i] == nc && r[j][i] > rank) {
                        rank = r[j][i]; now = j;
                    }
                }
            }
            res[now%2]++;
            lead = now;
        }
        cout << (res[0] > res[1] ? "NS" : "EW") << " " << max(res[0], res[1]) - 6 << endl;
    }
}


