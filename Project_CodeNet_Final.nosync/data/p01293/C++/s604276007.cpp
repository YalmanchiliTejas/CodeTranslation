#include <bits/stdc++.h>
using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n)-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(b)-1;i>=(a);--i)
#define ALL(a) a.begin(),a.end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
    if (a < b) { a = b; return true; }
    return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "{";
    int a = 0;
    for (auto &tp : mp) {
        if (a) os << ", "; a = 1;
        os << tp;
    }
    return os << "}";
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ":" << p.second;
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    for (;;) {
        char trump; cin >> trump;
        if (trump == '#') break;
        vector<vector<string>> cards(4, vector<string>(13));
        REP(i, 4) REP(j, 13) cin >> cards[i][j];

        map<char,int> ord;
        FOR(i, 2, 10) ord[i + '0'] = i;
        ord['T'] = 10;
        ord['J'] = 11;
        ord['Q'] = 12;
        ord['K'] = 13;
        ord['A'] = 14;

        vi win(4);

        int leader = 0;
        REP(j, 13) {
            bool playedTrump = 0;
            REP(i, 4) if (cards[i][j][1] == trump) playedTrump = 1;
            int ma = 0, maxI = -1;
            char suit = cards[leader][j][1];
            FOR(i, 0, 4) {
                int id = (i + leader) % 4;
                if (playedTrump and cards[id][j][1] != trump or !playedTrump and cards[id][j][1] != suit) continue;
                if (chmax(ma, ord[cards[id][j][0]])) maxI = id;
            }
            ++win[maxI];
            leader = maxI;
        }
        if (win[0] + win[2] > win[1] + win[3]) cout << "NS " << win[0] + win[2] - 6 << endl;
        else cout << "EW " << win[1] + win[3] - 6 << endl;
    }

    return 0;

}

