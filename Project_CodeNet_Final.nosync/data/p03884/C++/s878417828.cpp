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
fill_v(U &u,const V... v) {
    for (auto &e:u) fill_v<T>(e, v...);
}

int64 calc(string s) {
    int64 res = 0;
    vector<int64> cnt(8, 0);
    string fest = "FESTIVAL";
    REP(i, s.size()) {
        int64 id = fest.find(s[i]);
        if (id == 0) {
            cnt[id]++;
        } else if (id < 7) {
            cnt[id] += cnt[id-1];
        } else {
            res += cnt[6];
        }
    }
    return res;
}

int main(void) {
    int64 K;
    cin >> K;
    vector<int64> cnt(7, 0);
    vector<PLL> card;
    REP(i, 7) cnt[i] = 1;
    card.emplace_back(cnt.back(), 1);
    int64 sum = 7;
    int64 add = 1;
    while (card.back().fs*add < INF_LL) {
        while (1) {
            vector<int64> cnt2(cnt);
            cnt2[0] += add;
            FOR(i, 1, 7) {
                cnt2[i] += cnt2[i-1]* add;
            }
            if (cnt2.back() >= card.back().fs*(add+1)) {
                swap(cnt, cnt2);
                card.emplace_back(cnt.back(), add);
                sum += add * 7;
                break;
            } else {
                add++;
            }
        }
    }
    card.emplace_back(2*INF_LL, INF_LL);
    vector<int64> L;
    while (K) {
        int64 id = upper_bound(all(card), PLL(K, INF_LL))- card.begin();
        id--;
        K -= card[id].fs;
        L.push_back(id);
    }
    string fest = "FESTIVAL";
    string res = "";
    int64 idx = 0;
    reverse(all(L));
    REP(i, card.size()-1) {
        REP(j, 7) {
            res += string(card[i].sc, fest[j]);
        }
        while (idx < L.size() && L[idx] == i) {
            res += "L";
            idx++;
        }
    }
    cout << res << endl;
}
