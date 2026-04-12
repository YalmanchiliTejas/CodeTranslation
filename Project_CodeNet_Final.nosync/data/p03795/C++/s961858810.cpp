#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cctype>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int n; cin >>n;

    int x = 800*n;
    int y = (n/15)*200;

    cout << x - y << endl;

    return 0;
}


