#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
//#include <iostream>
//#include <sstream>
using namespace std;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define pf printf
#define sf scanf
#define fr(i, a, b) for(int i = a ; i < b ; i++)
#define frr(i, a, b) for(int i = a ; i >= b ; i--)
#define tr(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define trr(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define its(x) static_cast< ostringstream & >( ( ostringstream() << dec << x ) ).str()
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define deb(x) cout << #x" = " << x << '\n'
#define debd(x) pf("%s = %d\n", #x, x)
#define debs(x) pf("%s = %s\n", #x, s)
#define debll(x) pf("%s = %lld\n", #x, x)
#define has(cont, x) ((cont).find((x)) != (cont).end())
#define sz(x) ((int)(x).size())
//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
//bitmask
int onbit(int x, int pos) {x |= (1 << pos); return pos;}
int offbit(int x, int pos) {x &= ~(1 << pos); return x;}
int test(int x, int pos) {return x & (1 << pos);}
int flip(int x, int pos) {x ^= (1 << pos); return x;}
int lsb(int x) {return x & (-x);}
int onbitall(int x, int pos) {x = (1 << pos)-1; return x;}
//constants
const double EPS = 1e-9;
const double PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
//moves
const int dx1[] = {0, 1, 0, -1};
const int dy1[] = {1, 0, -1, 0};
const int dx2[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
//    freopen("input.in", "r", stdin);
	int a, b, c;
	sf("%d %d %d", &a, &b, &c);
	a *= 100;
	b *= 10;
	puts((a+b+c) % 4 == 0 ? "YES" : "NO");
	return 0;
}