#include<bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define debug(x) cout << #x <<" = " << x << endl
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define printvpair(v) for(int i = 0 ; (i) < (v.size()) ; ++i) cout << v[i].first  <<" " << v[i].second << endl;
#define printv(v) for(int i = 0 ; (i) < (v.size()) ; ++i) cout << v[i] << " "; cout << endl;

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = 1000000000;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};

const int N = 100001;
int a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int a,b,c;
	cin >> a >> b >> c;
	int x = x * 100 + b * 10 + c;
	if (x % 4 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
  	return 0;
}


