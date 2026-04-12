// acdart
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cstdlib>
#include <list>
#include <limits.h>
#include <utility>
#include <functional>
#include <deque>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define F first
#define S second
#define MOD9 1000000009ll
#define MOD7 1000000007ll
#define MOD
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define SZ(x) ((int)(x).size())
#define MAXN 10010
#define MAXM
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/


int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%d", n * 800 - (n / 15) * 200);
}