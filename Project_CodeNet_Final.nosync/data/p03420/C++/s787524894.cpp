#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define X first
#define Y second

#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define err(x) cerr << #x << " = " << x << endl;
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for(typeof((c).begin())v=(c).begin();v!=(c).end();++v)
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

clock_t start;
void Time(bool timeIt) {
	if (!timeIt) return;
	clock_t end = clock();
	double elapsed_time = ((db)end - (db)start) / (db)CLOCKS_PER_SEC;
	printf("Time elapsed = %0.4lf\n", elapsed_time); 
}

#define LINF (long long)1e18
#define EPS 1e-9
#define INF 1000000007ll
#define SIZE 100010
#define MAX_A 1000010

int main() {
	start = clock();

	ll n, k, ans = 0;
	cin >> n >> k;

	if (k == 0) cout << n * n << endl;
	else {
		for (ll b = k + 1 ; b <= n ; ++b) {
			ans += (b - k) * (n / b) + max(0ll, n % b - k + 1);
		}
		cout << ans << endl;
	}


	Time(false);
	return 0;
}