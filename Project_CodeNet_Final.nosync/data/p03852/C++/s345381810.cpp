#include <bits/stdc++.h>
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
#define INF 2147483647

signed main() {
	char c;
	cin >> c;
	string a = "aiueo";
	cout << (a.find(c) != string::npos ? "vowel" : "consonant") << endl;
}
