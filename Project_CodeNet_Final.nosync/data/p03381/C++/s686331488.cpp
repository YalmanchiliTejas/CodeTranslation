#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <set>
#include <map>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;
using VP = vector<P>;

int main() {
    long n;
    cin >> n;
    VI v;
    REP(i,n) {
        long a;
        cin >> a;
        v.push_back(a);
    }
    VI w(v);
    sort(w.begin(), w.end());
    long sm = w[n/2-1];
    long bm = w[n/2];
    
    REP(i,n) {
        if (v[i] >= bm) {
            cout << sm << endl;
        } else {
            cout << bm << endl;
        }
    }
}
