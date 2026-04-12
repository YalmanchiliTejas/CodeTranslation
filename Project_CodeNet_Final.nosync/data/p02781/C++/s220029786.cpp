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


long long com(long long N, long long R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

long long pow(long long N, long long k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) res *= N;
    return res;
}

string S;
int N, K;

long long solve(int i, int k, int smaller) {
    if (i == N) {
        if (k == 0) return 1;
        else return 0;
    }
    if (N - i < k) return 0;
    if (k == 0) return 1;
    
    if (smaller) {
        return com(N-i, k) * pow(9, k);
    }
    else {
        if (S[i] == '0') {
            return solve(i+1, k, false);
        }
        else {
            long long zero = solve(i+1, k, true);
            long long aida = solve(i+1, k-1, true) * (S[i] - '1');
            long long icchi = solve(i+1, k-1, false);
            return zero + aida + icchi;
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    while (cin >> S >> K) {
        N = S.size();
        cout << solve(0, K, false) << endl;
    }
}
















