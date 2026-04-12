#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define sc second
#define ALL(x) x.begin(), x.end()
#define RALL(X) x.begin(), x.end()
#define FOR(i, n, k) for(i=0; i<n; i+=k)
#define FO(i, n, k) for(i=1; i<=n; i+=k)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define N 100005
#define mid ((l+r)/2)
#define dbg(x) (cerr << #x << " : " << x << endl)
#define endl "\n"
#define MOD 100000009

using namespace std;

typedef long long int lli;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mx = -1, res = 0;
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		if(m >= mx){
			res++;
			mx = m;
		}
	}
	cout << res;
	return 0;
}