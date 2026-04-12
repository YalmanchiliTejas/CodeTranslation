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
#include <deque>
#include <algorithm>
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

int main() {
    ll k, a, b;
    cin >> k >> a >> b;

    if (a >= k){
        cout << 1 << endl;
        return 0;
    }
    if (b >= a){
        cout << -1 << endl;
        return 0;
    }
    cout << (k - a + a - b - 1) / (a - b) * 2 + 1 << endl;


    return 0;
}


