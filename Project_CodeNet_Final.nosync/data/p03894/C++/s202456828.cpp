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
#include <array>
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
typedef vector<double> VD;

int main() {
    int n, q;
    cin >> n >> q;
    int x = 0;
    VI a(n);
    a[0] = a[1] = 1;
    while (q--){
        int s, t;
        scanf("%d %d", &s, &t);
        s--;
        t--;
        swap(a[s], a[t]);
        if (x == s) x = t;
        else if (x == t) x = s;

        if (x > 0) a[x-1] = 1;
        if (x < n-1) a[x+1] = 1;
    }

    int ans = 0;
    REP(i,n) ans += a[i];
    cout << ans << endl;

    return 0;
}