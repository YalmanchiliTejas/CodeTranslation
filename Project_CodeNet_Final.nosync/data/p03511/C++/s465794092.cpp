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
    int l;
    string s, t;
    cin >> l >> s >> t;
    int n = s.length(), m = t.length();
    string ans = string(l, '{');

    int p1 = -1, q1 = -1, p2, q2;
    REP(x,l/n+1){
        int y = (l - x*n) / m;
        if (x*n + y*m != l) continue;
        if (p1 == -1){
            p1 = x;
            q1 = y;
        }
        p2 = x;
        q2 = y;
    }

    string s1, s2, t1, t2;
    REP(i,p1) s1 += s;
    REP(i,p2) s2 += s;
    REP(i,q1) t1 += t;
    REP(i,q2) t2 += t;

    if (s1 + t1 < ans) ans = s1 + t1;
    if (t1 + s1 < ans) ans = t1 + s1;
    if (s2 + t2 < ans) ans = s2 + t2;
    if (t2 + s2 < ans) ans = t2 + s2;
    cout << ans << endl;

    return 0;
}


