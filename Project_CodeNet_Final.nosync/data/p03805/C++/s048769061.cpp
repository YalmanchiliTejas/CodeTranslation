#define FNAME ""
 
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
 
#define hash padjf9srpi
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
 
#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif
 
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;                                                                                                                                                                                      
typedef vector <int> vi;
 
template <class T> T sqr(const T &a) {return a * a;}
 
int g[10][10], p[10];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int s, f;
    	cin >> s >> f;
    	s--,f--;
    	g[s][f] = g[f][s] = 1;
    }
    for (int i = 0; i < n; i++) p[i] = i;
    int ans =0;
    do {
    	bool ok = 1;
    	for (int i = 0; i < n - 1; i++) {
    		if (!g[p[i]][p[i + 1]]) ok = 0;
    	}
    	if (p[0] != 0) ok = 0;
    	ans += ok;
    } while (next_permutation(p, p + n));
    cout << ans << endl;
 
    
    
    return 0;
}