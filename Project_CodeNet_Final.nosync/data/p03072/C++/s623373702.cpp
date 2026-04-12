#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstdlib>
#include<vector>
#include<set>
#include<deque>
#include<queue>
#include<math.h>
#include<chrono>
#include<list>
#include<random>
#include<bitset>
#include<assert.h>
#include<ctime>
#include<cstdio>
#include <unordered_map>
using namespace std;
ifstream fi("zinput.txt");
ofstream fo("output.txt");
#define fast_input() {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
#define ll long long
#define For(i,n) for (int(i) = 0; (i)< (int)(n); (i)++)
#define For1(i,n) for (int(i) = 1; (i) <= (int)(n); (i)++)
#define Forlr(i,l,r) for (int(i) = (int)(l); (i) <= (int)(r); (i)++)
#define Forrl(i,r,l) for (int(i) = (int)(r); (i) >= (int)(l); (i)--)
#define all(a) a.begin(), a.end() 
#define pb push_back
#define pp pop_back
#define mp make_pair
#define PI 3.14159265
#define putno return cout <<"NO", 0;
#define putyes return cout <<"YES", 0;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef map<int, int> mii;
//const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;
//DSU
/*
int p[ N], r[N];
void init(int n) {
	For(i, n) {
		p[i] = i;
	}
}
int get(int x) {
	if (p[x] != x) {
		p[x] = get(p[x]);
	}
	return p[x];
}
bool uni(int x, int y) {
	x = get(x); y = get(y);
	if (x == y) {
		return false;
	}
	if (r[x] >= r[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
	}
	if (r[x] == r[y]) {
		r[x]++;
	}
	return true;
}
*/

// So mu
/*
int power(int x, unsigned int y, int p)
{
	int res = 1; // Initialize result

	x = x % p; // Update x if it is more than or
	// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}
*/

// ReadHexa
/*
bitset<16400> b[4101];
void readHexa()
{
	For(i, n)
	{
		string st;
		cin>> st;
		For(j, m/4)
		{
			int x;
			if (st[j] >= 'A' && st[j] <= 'F')
				x = st[j] - 'A' + 10;
			else x = st[j] - '0';
			for (int k = 4; k; --k, x >>= 1)
				b[i][j * 4 + k] = x & 1;
		}
	}
}
*/

// nChoosek
/*
ll nChoosek(ll n, ll k)
{
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	ll result = n;
	for (ll i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}
*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
MIKUNO - 15/02/1999
*/
int n, m, k, cnt, rs, q;
int x, y;
//	priority_queue <ll, vector<ll>, greater<ll> > q;
//ll n, m, q, k, pos, t, cnt, rs1, check;
ll maxx = -1e9, minn = 1e9;
int ma = -1e9, mi = 1e9;
const int maxn = 2*N;
const ll MOD = 1e9 + 7;
int a[100];
int main()
{
	fast_input();
	cin >> n;
	int ma = 0;
	For(i, n)
	{
		cin >> a[i];
		if (a[i] >= ma)
		{
			rs++;
			ma = a[i];
		}
	}
	cout << rs;
}