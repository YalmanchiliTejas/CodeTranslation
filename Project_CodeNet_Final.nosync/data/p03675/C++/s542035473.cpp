#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	REP(i, n) cin>>a[i];
	vector<int> b;
	for(int i = n - 1; i >= 0; --i) {
		if(i % 2 == 0) b.pb(a[i]);
	}
	for(int i = 0; i < n; ++i) {
		if(i % 2 == 1) b.pb(a[i]);
	}
	if(n % 2 == 1) {
	REP(i, n) {
		cout<<b[i];
		if(i != n - 1) cout<<" ";
		else cout<<endl;
	}
	} else {
		REP(i, n) {
			cout<<b[n - i - 1];
			if(i != n - 1) cout<<" ";
			else cout<<endl;
		}
	}
}
