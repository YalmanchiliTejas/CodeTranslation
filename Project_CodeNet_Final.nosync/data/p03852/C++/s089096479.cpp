#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"

#define REP(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(a) begin(a),end(a)
#define ifnot(a) if(not (a))
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define LINF ((ll)1 << 60)
#define INF (1 << 28)
template<typename T>
void chmax(T& a, T b) {
        if (a < b) a = b;
}
template<typename T>
void chmin(T& a,T b) {
        if (a > b) a = b;
}
int T = 1;
//.....................
ull mod = (int)1e9 + 7;
const int MAX = (int)2e5 + 5;

bool isVowel(char c) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        rep(i, 5) {
                if (c == vowels[i]) return true;
        }
        return false;
}

void solve() {
        char c;
        cin >> c;
        cout << (isVowel(c) ? "vowel" : "consonant") << endl;
}

signed main() {
        cout << fixed << setprecision(20);
        rep(i, T) {
                solve();
        }
        return 0;
}