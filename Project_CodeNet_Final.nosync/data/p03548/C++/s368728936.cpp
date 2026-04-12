#include <bits/stdc++.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define pii pair < int , int >
#define task "flight"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFL = 3e18 + 1;
const double pi = acos(-1.0);

void files (string s) {
  if (fopen ((s + ".in").c_str(),"r")) {
  	freopen ((s + ".in").c_str(),"r", stdin);
    freopen ((s + ".out").c_str(),"w", stdout);
  }
}
    
int main () {
	files ("");

	int x, y, z;
	cin >> x >> y >> z;
                  
	cout << (x - z) / (y + z);

	return 0;
}