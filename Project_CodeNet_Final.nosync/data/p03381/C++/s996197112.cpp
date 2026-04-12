#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i, n) for ( int i = 0 ; i < (n); i++ )
#define All(v) v.begin(), v.end()

typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1e18+1;

signed main() {
	int N;
	cin >> N;
	vector<int> a(N);
	Rep(i, N) cin >> a[i];
	vector<int> b = a;
	sort(All(b));
	int c = b[N/2-1], d = b[N/2];
	Rep(i, N) {
		if ( a[i] <= c ) cout << d << endl;
		else cout << c << endl;
	}
	return 0;
}
