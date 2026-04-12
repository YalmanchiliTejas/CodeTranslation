#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }

const int MAX = 3100;
long long n;
long long MOD = 1000000007;

long long S[MAX][MAX];

void calc_strling() {
    memset(S, 0, sizeof(S));
    S[0][0] = 1;
    for (long long n = 1; n < MAX-1; ++n) {
        for (long long k = 1; k <= n; ++k) {
            S[n][k] = (S[n-1][k-1] + ((S[n-1][k] * k) % MOD)) % MOD;
        }
    }
}

long long ef(long long n, long long k) {
    long long res = S[n][k];
    res += (S[n][k+1] * (k+1)) % MOD;
    return (res % MOD);
}

long long Com[MAX][MAX];
void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) % MOD;
        }
    }
}

long long twopow[MAX*MAX];
void twobeki() {
    twopow[0] = 1;
    for (int i = 0; i < MAX*MAX; ++i) {
        twopow[i+1] = (twopow[i] * 2) % MOD;
    }
}


long long twotwopow[MAX];
long long mpow(long long a, long long n, long long m) {
    if (n == 0) return 1 % m;
    long long t = mpow(a, n/2, m);
    t = (t * t) % m;
    if (n & 1) t = (t * a) % m;
    return t;
}
void twotwobeki() {
    for (long long i = 0; i < MAX; ++i) {
        long long sisuu = mpow(2LL, i, MOD-1);
        twotwopow[i] = mpow(2LL, sisuu, MOD);
    }
}


int main() {
    while (cin >> n >> MOD) {
        calc_strling();
        calc_com();
        twobeki();
        twotwobeki();
        
        long long res = 0;
        for (int k = 0; k <= n; ++k) {
            long long tmp = (Com[n][k] * twotwopow[n-k]) % MOD;
            long long nakami = 0;
            for (int k2 = 0; k2 <= k; ++k2) {
                //cout << k << ", " << k2 << ": " << ef(k, k2) << ", " << twopow[(n-k)*k2] << endl;
                long long add = (ef(k, k2) * twopow[(n-k)*k2]) % MOD;
                nakami += add;
                nakami %= MOD;
            }
            tmp *= nakami;
            tmp %= MOD;
            
            //COUT(nakami);COUT(tmp);
            
            if (k & 1) {
                res = (res - tmp + MOD) % MOD;
            }
            else {
                res = (res + tmp) % MOD;
            }
        }
        
        cout << res << endl;
    }
}












