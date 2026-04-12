#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vs s(n);
    forn(i, n) cin >> s[i];
    int x = 0, y = 0;
    int cnt = 0;
    forn(i, n) {
        forn(j, m) {
            if (s[i][j] == '#') cnt++;
        }
    }
    if (cnt != n + m - 1) {
        puts("Impossible");
        return 0;
    }
    forn(it, cnt - 1) {
        bool canX = x + 1 < n && s[x + 1][y] == '#';
        bool canY = y + 1 < m && s[x][y + 1] == '#';
        if (canX ^ canY) {
            if (canX) x++; else y++;
        } else {
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    return 0;
    return 0;
}
