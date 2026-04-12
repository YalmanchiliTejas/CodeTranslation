#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1e9+7;
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

int main(){
    int A, B, C, X, Y, m = INF;
    cin >> A >> B >> C >> X >> Y;
    REP(i, max(X,Y)+1){
        m = min(2*C*i + A*max(0,X-i) + B*max(0,Y-i), m);
    }
    cout << m << endl;
}
