// acdart C++
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <bitset>
#include <cctype>
#include <fstream>
#include <numeric>
#include <utility>
#include <iomanip>
#include <complex>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector< vi > vvi;
typedef vector< vd > vvd;
typedef vector< vll > vvll;
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define F first
#define S second
#define PI 3.1415926535897932384626433832795
#define mod9 1000000009ll
#define mod7 1000000007ll
#define inf 0x3f3f3f3f
#define inf8  1023456789ll
#define inf16 10000000000000000ll
#define SZ(x) ((int)(x).size())
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for(int i=0;i<sz(v);++i)
#define lp(i, n) for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n) for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n) for(int i=(j);i>=(int)(n);--i)
#define gcd(x, y) __gcd(x, y)
#define lson (id << 1)
#define rson (id << 1 | 1)
#define lowb(x) (x & (-x))
#define eps 1e-7
/*********default*********/
#define maxm
#define maxn

int main()
{
	// ios::sync_with_stdio(false);
	char s[10];
	
	scanf("%s", s);
	int x = strlen(s);
	for (int i = 0; i + 1 < x; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			puts("Yes");
			return 0;
		}
	} 
	puts("No");
}
