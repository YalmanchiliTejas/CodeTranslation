#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	while(1) {
		int n, a, b, c, x;
		cin>>n>>a>>b>>c>>x;
		if(n == 0 && a == 0 && b == 0 && c == 0 && x == 0) break;
		int roc = 0;
		vector<int> y(n);
		REP(i, n) cin>>y[i];
		int res = 0;
		while(res < 10001) {
			if(x == y[roc]) {
				++roc;
				if(roc == n) break;
			}
			x = (a * x + b) % c;
			++res;
		}
		if(res != 10001) cout<<res<<endl;
		else cout<<-1<<endl;
	}
}