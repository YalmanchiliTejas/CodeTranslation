#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, deque<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ for(auto it : P) { s << "<" << it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ for(auto it : P) { s << "<" << it.first << "->" << it.second << "> "; } return s << endl; }


long long solve() {
    long long N, X, M;
    cin >> N >> X >> M;

    const int MAXD = 55;
    vector<vector<long long>> nex(MAXD+1, vector<long long>(M, -1)),
                              sum(MAXD+1, vector<long long>(M, 0));
    for (long long r = 0; r < M; ++r) {
        nex[0][r] = r * r % M;
        sum[0][r] = r;
    }
    for (int p = 0; p < MAXD; ++p) {
        for (int r = 0; r < M; ++r) {
            nex[p+1][r] = nex[p][nex[p][r]];
            sum[p+1][r] = sum[p][r] + sum[p][nex[p][r]];
        }
    }
    long long res = 0;
    int cur = X;
    for (int p = MAXD; p >= 0; --p) {
        if (N & (1LL<<p)) {
            res += sum[p][cur];
            cur = nex[p][cur];
        }
    }
    return res;
}

int main() {
    cout << solve() << endl;
}