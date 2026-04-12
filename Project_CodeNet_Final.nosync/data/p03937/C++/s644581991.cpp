#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int main() {
    int h, w, c = 0;
    cin >> h >> w;
    REP(i,h) {
        REP(j,w) {
            char a;
            cin >> a;
            if (a == '#') c++;
        }
    }
    
    if (c == h + w - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
