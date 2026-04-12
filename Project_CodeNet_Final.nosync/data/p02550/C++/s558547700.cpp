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

    vector<int> ord(M, -1); // かつて来た地点を求める
    vector<long long> rireki, syu;
    long long res = 0;
    for (int n = 0; n < N; ++n) {
        // かつて来た地点に戻ったら
        if (ord[X] != -1) {
            int p = ord[X];
            for (long long i = p; i < n; ++i) syu.push_back(rireki[i]);
            break;
        }
        ord[X] = n;
        rireki.push_back(X);
        res += X;
        X = (X * X) % M;
    }
    N -= rireki.size();

    // 戻る前に N 項目に到達した場合
    if (N == 0) return res;

    // 周期の累積和をとる
    vector<long long> sum(syu.size() + 1, 0);
    for (int i = 0; i < syu.size(); ++i) sum[i+1] = sum[i] + syu[i];

    // 周期を q 週して r あまる
    long long q = N / syu.size();
    long long r = N % syu.size();
    res += sum[syu.size()] * q + sum[r];
    return res;
}

int main() {
    cout << solve() << endl;
}