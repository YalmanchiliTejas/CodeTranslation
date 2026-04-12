//#define LOCAL

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <set>

//#define int long long
//typedef long long ll;
using ll = long long;
using R = double;

//#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)

#define MOD 1000000007

using namespace std;

typedef vector<int> V;
typedef vector<V> VV;



signed main()
{
    int r, g, b;

    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
