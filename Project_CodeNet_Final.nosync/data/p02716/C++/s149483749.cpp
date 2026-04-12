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
 
 
const long long INF = 1LL<<60;
int N;
vector<long long> A;
 
long long solve() {
    vector<long long> left(N+1, 0), right(N+1, 0);
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            left[i+1] = left[i] + A[i];
            right[i+1] = right[i] + A[N-i-1];
        }
        else left[i+1] = left[i], right[i+1] = right[i];
    }
    vector<long long> dp(N+1, -INF);
    dp[0] = 0;
    for (int i = 2; i <= N; i += 2) {
        chmax(dp[i], dp[i-2] + A[i-1]);
        chmax(dp[i], left[i-2] + max(A[i-1], A[i-2]));
    }
 
    if (N % 2 == 0) return dp[N];
    long long res = -INF;
    for (int i = 0; i <= N; i += 2) {
        chmax(res, dp[i] + right[N-i-1]);
    }
 
    //COUT(left); COUT(right); COUT(dp);
 
    return res;
}
 
int main() {
    while (cin >> N) {
        A.resize(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << solve() << endl;
    }
}
 
 
 
 