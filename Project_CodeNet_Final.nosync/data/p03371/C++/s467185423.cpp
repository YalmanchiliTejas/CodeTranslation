#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
typedef long long ll;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int a,b,c,x,y; cin >>a>>b>>c>>x>>y;
    int res = 0;

    int mn = min(x,y);
    res += mn*min(a+b, 2*c);
    res += (x-mn)*min(a, 2*c);
    res += (y-mn)*min(b, 2*c);

    cout << res << endl;
    return 0;
}

