#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ for(auto it : P) { s << "<" << it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ for(auto it : P) { s << "<" << it.first << "->" << it.second << "> "; } return s << endl; }


const int INF = 1<<29;
struct tup {
    int a, b, c;
    tup(int a, int b, int c) : a(a), b(b), c(c) {}
};

int solve(int N) {
    int offset = 0;
    int a, b, end;
    cin >> a >> b; --a, --b;
    vector<vector<int>> A;
    for (int i = 0; i < N-1; ++i) {
        vector<int> v(3);
        for (int j = 0; j < 3; ++j) cin >> v[j], --v[j];
        sort(v.begin(), v.end());
        if (v[0] == v.back()) ++offset;
        else A.push_back(v);
    }
    cin >> end; --end;
    vector<vector<int>> dp(N, vector<int>(N, -INF));
    dp[a][b] = dp[b][a] = 0;
    int ma = 0;
    vector<int> vma(N, -INF);
    vma[a] = vma[b] = 0;

    for (auto v : A) {
        vector<tup> chs;

        // 3 つのうち 2 つが一緒のとき
        if (v[0] == v[1]) {
            for (int p = 0; p < N; ++p) {
                chs.emplace_back(p, v[2], dp[p][v[1]] + 1);
            }
        }
        else if (v[1] == v[2]) {
            for (int p = 0; p < N; ++p) {
                chs.emplace_back(p, v[0], dp[p][v[1]] + 1);
            }
        }
        // 前の 2 個が一緒
        {
            chs.emplace_back(v[1], v[2], dp[v[0]][v[0]] + 1);
            chs.emplace_back(v[2], v[0], dp[v[1]][v[1]] + 1);
            chs.emplace_back(v[0], v[1], dp[v[2]][v[2]] + 1);
        }
        // 前の 2 個を共に捨てる
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                chs.emplace_back(v[i], v[j], ma);
            }
        }
        // 前のうち 1 個を捨てる
        for (int i = 0; i < 3; ++i) {
            for (int p = 0; p < N; ++p) {
                chs.emplace_back(p, v[i], vma[p]);
            }
        }

        // change
        for (auto ch : chs) {
            int a = ch.a, b = ch.b, val = ch.c;
            chmax(dp[a][b], val);
            chmax(dp[b][a], val);
            chmax(ma, val);
            chmax(vma[a], val);
            chmax(vma[b], val);
        }
    }
    int res = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            if (a == end && b == end) chmax(res, dp[a][b] + 1);
            else chmax(res, dp[a][b]);
        }
    }
    return res + offset;
}

int main() {
    int N;
    while (cin >> N) cout << solve(N) << endl;
}