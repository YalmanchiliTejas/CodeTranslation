#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

ll pow2[61];

ll dfs(ll x, ll n) {
    ll l = pow2[n + 1] - 3;
    ll p = pow2[n] - 1;
    if(x == 1) return 0;
    else if(x < l + 1) return dfs(x - 1, n - 1);
    else if(x == l + 1) return p;
    else if(x == l + 2) return p + 1;
    else if(x < l * 2 + 2) return p + 1 + dfs(x - (l + 2), n - 1);
    else return p * 2 + 1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    pow2[0] = 1;
    FOR(i, 1, 60) pow2[i] = pow2[i - 1] * 2; 
    ll n, x;
    cin >> n >> x;
    cout << dfs(x, n) << endl;
    return 0;
}
