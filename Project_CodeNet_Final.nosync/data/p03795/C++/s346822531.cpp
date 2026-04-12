#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;

#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MAX_V 100000

#define MOD 1000000007L
#define INF 100000000000

signed main() {
	int n;
	cin >> n;
	cout << (n * 800 - ((n / 15) * 200)) << endl;
}
